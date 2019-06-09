pathA = 'files/fileA.txt'
pathB = 'files/fileB.txt'

def compareFiles():

	fc = open('files/Console.txt', 'w+')

	dataA = open(pathA).read().splitlines()
	dataB = open(pathB).read().splitlines()

	lenA = len(dataA)
	lenB = len(dataB)

	i = 0
	j = 0

	while i < lenA and j < lenB:
		if str(dataA[i]) != str(dataB[j]):
			fc.write(str(i+1) + ": " + dataA[i] + " " + dataB[j] + "\n")

		i += 1
		j += 1

	fc.write('-----------------------------\n')
	fc.write('Both files compared successfully\n')
	fc.close()
