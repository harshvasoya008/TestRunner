import subprocess
import sys;
import CustomTestParser


def compileAndRun(problemcode, problemtype):

    # ------ Parsing the tests -------
    CustomTestParser.parse_test(problemcode)
    testcases = str(open('tests/' + problemcode + '.txt').read()).split('<!-----!>')

    # ------ Compiling the source file -------
    if problemtype == '.cpp':
        objectfile = 'codes/source.exe'
        if sys.platform == 'linux' or sys.platform == 'darwin':
            objectfile = 'codes/source'

        command = 'g++ "codes/' + problemcode + problemtype + '" -o ' + objectfile + ' > files/Console.txt 2>&1'
        subprocess.call(command, shell=True)
    
    elif problemtype == '.java':
        command = 'javac -nowarn "codes/' + problemcode + problemtype + '" > files/Console.txt 2>&1'
        subprocess.call(command, shell=True)

    if len(open('files/Console.txt').read()) > 0:   # exit if there is error in compilation
        return exit(1)

    # ------- Running the testcases -------
    cnt = 0
    num = 0
    fc = open('files/Console.txt', 'a+')

    for i in range(len(testcases)):
        if len(testcases[i]) == 0:
            continue

        fi = open('files/tempin.txt', 'w+')
        sample_input = testcases[i].split('::')[0]
        fi.write(sample_input)
        fi.close()

        # Running the source file
        if problemtype == '.cpp':
            runFile = 'codes\\source.exe'
            if sys.platform == 'linux' or sys.platform == 'darwin':
                runFile = './codes/source'

            subprocess.call(runFile + ' < files/tempin.txt > files/tempout.txt', shell=True)

        elif problemtype == '.java':
            subprocess.call('cd ./codes && java "'+problemcode+'" < ../files/tempin.txt > ../files/tempout.txt', shell=True)

        sample_output = testcases[i].split('::')[1]
        actual_output = str(open('files/tempout.txt').read()).strip()

        content = actual_output.splitlines()
        actual_output = ''
        for x in content:
            x = x.strip()
            actual_output += x + '\n'
        actual_output = actual_output.strip()

        num += 1
        if num == 1:
            fc.write('Status: Problem "' + problemcode + '"\n')
            fc.write('-----------------------------\n')
        fc.write('Test ' + str(num) + ': ')

        if sample_output == actual_output:
            fc.write('Passed.\n\n')
            cnt += 1
        else:
            fc.write('Failed!\n')
            fc.write('Input:\n' + sample_input + '\n\n')
            fc.write('Actual output:\n' + actual_output + '\n')
            fc.write('Expected output:\n' + sample_output + '\n\n')

    fc.write('-----------------------------\n')
    fc.close()

    return cnt == num
