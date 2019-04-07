def parse_test(problemcode):
    content = str(open('files/CustomTest.txt').read()).splitlines()
    if len(content)<4 or len(content[1])==0:    # if file format is changed or input is empty
        return

    content = str(open('files/CustomTest.txt').read()).split('@')
    content = content[1:]

    sample_input = content[0].strip().split(':\n')[1]
    sample_output = content[1].strip().split(':\n')[1]

    fp = open('tests/' + problemcode + '.txt', 'a+')
    fp.write('<!-----!>' + sample_input + '::' + sample_output)
    fp.close()

    fp = open('files/CustomTest.txt', 'w')
    fp.write('@Input:\n\n@Output:\n')
    fp.close()
