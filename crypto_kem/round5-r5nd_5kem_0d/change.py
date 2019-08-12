import os
import subprocess


for dname, dirs, files in os.walk("clean"):
    # new_word_lst = list()
    # word_lst = list()
    func_prefix = 'PQCLEAN_ROUND5{{ scheme|upper }}_CLEAN_'
    #function_lst = ['ceil_log2', 'print_hex', 'print_sage_s_matrix', 'print_sage_s_vector', 'print_sage_s_vector_matrix', 'print_sage_u_matrix', 'print_sage_u_vector', 'print_sage_u_vector_matrix', 'checked_calloc', 'checked_malloc', 'checked_realloc', 'conditional_constant_time_memcpy', 'constant_time_memcmp']
    function_lst = ['xef_reg']
    for fname in files:
        fpath = os.path.join(dname, fname)
        with open(fpath) as f:
            s = f.read()
        for function in function_lst:
            s = s.replace(function, func_prefix + function)
            # print(func_prefix + function)
        # for word in s.split("("):
        #     if "PQCLEAN_ROUND5{{ scheme|upper }}" in word:
        #         word_lst.append(word)
        #         if "_CLEAN" not in word:
        #             new_word_lst.append(word.replace("PQCLEAN_ROUND5{{ scheme|upper }}", "PQCLEAN_ROUND5{{ scheme|upper }}_CLEAN"))
        #         else:
        #             new_word_lst.append(word)
        # for i in range(len(new_word_lst)):    
        #     s = s.replace(word_lst[i], new_word_lst[i])
        with open(fpath, "w") as f:
            f.write(s)
