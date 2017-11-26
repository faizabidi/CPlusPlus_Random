#!/usr/bin/python
from datetime import datetime
from itertools import groupby, count

#########################################################
inp = raw_input('Enter a file:')
try:
	if(len(inp)) < 1 : inp = 'input.txt'
	file = open(inp)
except:
	print 'File not found\n'
	exit()
#########################################################	exit()
allData = list()
# Store all in lists separated by white space
for words in file:
	allData.append(words)
#########################################################	exit()
new_list = list()
multiline_index_list = list()
#########################################################
# Check if the string starts with a date
def check(start_string):
	if len(start_string) < 20 or \
			start_string[4] != '-' or start_string[7] != '-':
		
		return True
	else:
		return False
#########################################################
for words in allData:
	# If the word doesn't start with a date
	if check(words):
		multiline_index_list.append(allData.index(words))
		print words
# Make groups of the indexes that don't start with a date
groups = groupby(multiline_index_list, key=lambda item, c=count():item-next(c))
multiline_index_list = [list(g) for k, g in groups]
#########################################################
# Add the multiline messages to the original log data
for index in multiline_index_list:
	string = ""
	insert_index = index[0] - 1
	for sub_index in index:
		string+=allData[sub_index]
	print string
	allData[insert_index] += string

# Build a new list
for words in allData:
	if check(words):
		continue
	else:
		new_list.append(words)
#########################################################
startDate_input = new_list[0].strip()
endDate_input = new_list[1].strip()

# Convert start and end time to date and time
startDate = datetime.strptime(startDate_input, '%Y-%m-%dT%H:%M:%SZ')
endDate = datetime.strptime(endDate_input, '%Y-%m-%dT%H:%M:%SZ')

for words in new_list[2:]:
	# Split by white space to get date
	temp = words
	words = words.split()
	# Since some messages can be multiline, what that means is that we need to check if the starting of a line is indeed actually a date, which would imply a new log message
	date = words[0];
	words = temp
	words = words.splitlines()
	date = datetime.strptime(date, '%Y-%m-%dT%H:%M:%SZ')
	# Check if this date falls within the start and the end dates
	if date >= startDate and date < endDate:
		print '\n'.join(words)
