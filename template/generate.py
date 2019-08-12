#!/usr/bin/env python3

import copy
import glob
import jinja2
import os
import shutil
import subprocess
import yaml
import json

if 'ROUND5_DIR' not in os.environ:
    print("Must set environment variable ROUND5_DIR")
    exit(1)

def file_get_contents(filename, encoding=None):
    with open(filename, mode='r', encoding=encoding) as fh:
        return fh.read()

def file_put_contents(filename, s, encoding=None):
    with open(filename, mode='w', encoding=encoding) as fh:
        fh.write(s)

def load_instructions(filename):
    instructions = file_get_contents(os.path.join('template', filename), encoding='utf-8')
    instructions = yaml.safe_load(instructions)
    return instructions


instructions = load_instructions("generate.yml")

clean_files = ['META.yml', 'clean/Makefile', 'clean/Makefile.Microsoft_nmake']
for root, dirs, files in os.walk(os.path.join('template', 'kem_template', 'clean')):
    for filename in files:
        if ".c" in filename or ".h" in filename:
            clean_files.append(os.path.join('clean', filename))

for family in instructions['round5']:
    if family is None:
        break
    for scheme in family['schemes']:
        print(json.dumps(scheme, indent=2))
        scheme_name = "round5" + "-" + scheme['scheme']
        try:
            os.mkdir(os.path.join('crypto_kem', scheme_name))
        except:
            pass
        shutil.rmtree(os.path.join('crypto_kem', scheme_name), ignore_errors=True)
        subprocess.run([
            'cp',
            '-a',
            os.path.join('template', 'kem_template'),
            os.path.join('crypto_kem', scheme_name)
        ])
        templateloader = jinja2.FileSystemLoader(searchpath="./template/kem_template")
        templateEnv = jinja2.Environment(loader=templateloader)
        new_files = list()
        for file in clean_files:
            template = templateEnv.get_template(file)
            output = template.render(CRYPTO_ALGNAME=scheme['scheme'].upper().strip('D') + 'd', NIST_LEVEL=scheme['nist_level'], 
                                    PUBLICKEY_BYTES = scheme['publickey_bytes'], SECRETKEY_BYTES = scheme['secretkey_bytes'],
                                    CIPHERTEXT_BYTES = scheme['ciphertext_bytes'], CRYPTO_BYTES = scheme['crypto_bytes'],
                                    scheme=scheme['scheme'], lib_name=scheme_name)
            new_files.append(output)
        for i in range(len(clean_files)):
            file_put_contents(os.path.join('crypto_kem', scheme_name, clean_files[i]), new_files[i])
        subprocess.run([
            'cp',
            os.path.join(os.environ['ROUND5_DIR'], 'kem', scheme['scheme'].upper().strip('D') + 'd', 'r5_parameter_sets.h'),
            os.path.join('crypto_kem', scheme_name, 'clean', 'r5_parameter_sets.h')
        ], check=True)


