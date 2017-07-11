def returnArray(arr):
	summ = 0
	output = []
	for i in arr:
		summ+=i
		output.append(i)
	output.append(summ)
	return output

if __name__ == "__main__":
	array = [2,3,4.5]
	ans = returnArray(array)
	for j in ans:
		print j
	print ans