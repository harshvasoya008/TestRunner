from bs4 import BeautifulSoup
import urllib.request
import sys
import CompileAndRun
import FileTransfer
import FileCompare


contest_url = 'http://codeforces.com/contest/'

def get_sampletest(contestcode, problemcode):
    url = contest_url + str(contestcode) + '/problem/' + problemcode

    response = urllib.request.urlopen(url)
    content = response.read()
    response.close()

    src = str(BeautifulSoup(content, "html.parser").find('div', {'class': 'sample-test'}))
    soup = BeautifulSoup(src, "html.parser")

    src1 = soup.findAll('div', {'class': 'input'})
    src2 = soup.findAll('div', {'class': 'output'})

    fp = open('tests/' + problemcode + '.txt','w+')

    for i in range(len(src1)):
        x = str(BeautifulSoup(str(src1[i]), "html.parser").find('pre'))
        y = str(BeautifulSoup(str(src2[i]), "html.parser").find('pre'))

        x = x.replace('<pre>', '').replace('</pre>', '').replace('<br/>', '\n').strip()
        y = y.replace('<pre>', '').replace('</pre>', '').replace('<br/>', '\n').strip()

        test = x + '::' + y + ('<!-----!>' if i!=len(src1)-1 else '')
        fp.write(test)

    fp.close()

def parseTest():
    contest = str(open("files/Contest.txt").read()).splitlines()
    contestcode = contest[1]

    response = urllib.request.urlopen(contest_url+contestcode)
    content = response.read()
    response.close()

    problems = BeautifulSoup(content, "html.parser").find('table', {'class': 'problems'})
    no_of_problems = len(BeautifulSoup(str(problems), "html.parser").findAll('tr')) - 1

    for i in range(no_of_problems):
        problemcode = chr(65+i)
        get_sampletest(contestcode, problemcode)
        print('Test ' + chr(65+i) + ' parsed.')

    print('Test parsed successfully.')


if __name__ == '__main__':
    platform = str(open("files/Contest.txt").read().splitlines()[0])
    platform = platform[5:-5]

    if platform == 'Codeforces' and sys.argv[1] == 'Parse_Test':
        parseTest()
        exit(0)

    if sys.argv[1] == 'Run_Code':
        contestcode = str(open("files/Contest.txt").read().splitlines()[1])
        problemcode = str(open("files/Contest.txt").read().splitlines()[2])
        problemtype = str('.' + problemcode.split('.')[1])
        problemcode = problemcode.split('.')[0]

        allpassed = CompileAndRun.compileAndRun(problemcode, problemtype)

        fc = open('files/Console.txt', 'a+')
        if allpassed:
            fc.write('Pretest passed.')
            # Copying source code to destination folder
            FileTransfer.transfer(platform, contestcode, problemcode, problemtype)
        else:
            fc.write('Wrong Answer')
        fc.close()

    if sys.argv[1] == 'File_Compare':
        FileCompare.compareFiles()
