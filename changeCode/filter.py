import json

# 传入解码后的json文件，返回一个字符串数组，其中的每一个元素都是一个function
def get_functions(file_content):
    functions = []                           # 存储返回的字符串数组
    tokens = file_content['tokens']          # 存储所有读取的token

    # 当读到'FunctionDecl'类型的token时，开始加入元素，同时记录'{'和'}'的匹配情况，
    # 如果完全匹配，则调用get_function函数得到一个字符串结果
    index = 0
    while index < len(tokens):
        # 当读到'FunctionDecl'类型的token时，开始加入元素
        willBreak = False        # 判断是否需要跳出外层循环
        if tokens[index]['sem'] == 'FunctionDecl':
            temp_tokens = []
            # 如果是形如'int func(int, int);'的函数声明，需要去掉，这里假设负号的sem属性为'FunctionDecl'
            # 先一口气扫描到';'，如果所有的token都在一行，说明是形如上面提到的函数声明，干掉；反之，则进行函数分割
            temp_line_num = tokens[index]['line']       # 暂存当前token的行号
            is_just_func_decl = True;                  # 标记是否是简单的函数声明

            # 去除简单的函数声明
            index2 = index
            while index2 < len(tokens):
                current_token = tokens[index2]
                if current_token['line'] != temp_line_num:
                    is_just_func_decl = False
                if current_token['text'] == ';':
                    break
                index2 += 1
            if is_just_func_decl:
                index = index2 + 1
                continue

            # 进行正常的函数分割
            left_brace_num = 0
            right_brace_num = 0
            index2 = index
            while index2 < len(tokens):
                current_token = tokens[index2]
                if current_token['text'] == '{':
                    left_brace_num += 1
                elif current_token['text'] == '}':
                    right_brace_num += 1
                    if left_brace_num == right_brace_num:
                        break
                temp_tokens.append(current_token)
                index2 += 1

            # 将得到的分割好的token序列
            functions.append(get_function(temp_tokens))
            index = index2 + 1
            print(temp_tokens)
        else:
            index += 1

    return functions

# 传入上一步切割好的token数组，返回一个字符串，为一个function
def get_function(tokens):
    result_function = ''            # 最后返回的处理好的一个函数
    head_String = ''
    C_String = ''
    entity_counter = 1              # 计数，用来替换变量名，格式entity_i
    line_num = tokens[0]['line']    # 记录当前的行号，用来进行换行操作
    formals = []
    flag = False
    variable_match = {}


    return '123'


if __name__ == '__main__':
    file = open('sample.json', errors='ignore')
    file_content = json.loads(file.read())

    result = get_functions(file_content)

    for function in result:
        print(function)
        print('\n\n')

