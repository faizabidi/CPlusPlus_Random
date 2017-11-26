from datetime import datetime
from itertools import groupby, count

# Input data
startDate_input = str(raw_input(''))
endDate_input = str(raw_input(''))
num_of_records = input('')

# Make a list of records
allData = list()

for i in range(0, num_of_records):
	allData.append(str(raw_input('')))
#########################################################
# To take care of multilines, make a new list
new_list = list()
# This list will contain all the indices of the multilines
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
# Make groups of the indexes that don't start with a date
groups = groupby(multiline_index_list, key=lambda item, c=count():item-next(c))
multiline_index_list = [list(g) for k, g in groups]
#########################################################
# Add the multiline messages to the original log data
for index in multiline_index_list:
	# Had to add a new line character to preserve new lines in the multilines
	string = "\n"
	insert_index = index[0] - 1
	for sub_index in index:
		# Add a new line at the end, again to preserver multilines
		string += allData[sub_index] + "\n"
	allData[insert_index] += string

# Build a new list
for words in allData:
	if check(words):
		continue
	else:
		new_list.append(words)
#########################################################
# Convert start and end time to date and time
startDate = datetime.strptime(startDate_input, '%Y-%m-%dT%H:%M:%SZ')
endDate = datetime.strptime(endDate_input, '%Y-%m-%dT%H:%M:%SZ')

for words in new_list:
	temp = words
	# Split by white space to get date
	words = words.split()
	# Since some messages can be multiline, what that means is that we need to check if the starting of a line is indeed actually a date, which would imply a new log message
	date = words[0];
	# Get the original value of words and now split by lines. We need to do this to preserve newlines in multilines
	words = temp
	words = words.splitlines()
	date = datetime.strptime(date, '%Y-%m-%dT%H:%M:%SZ')
	# Check if this date falls within the start and the end dates
	if date >= startDate and date < endDate:
		print '\n'.join(words)
