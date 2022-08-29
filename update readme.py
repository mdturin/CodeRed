import os
from os.path import isfile, join

def get_all(path):
	try:
		cur_files = [f for f in os.listdir(path)]
		return cur_files
	except:
		return []
		
def is_valid_file(path):
	if '.' in path:
		return False
	return True

def get_dir(path):
	_all = get_all(path)
	all_dir = []
	for f in _all:
		new_path = join(path, f)
		if not isfile(new_path) and is_valid_file(f):
			all_dir.append(f)
	return all_dir
	
ext = ['exe', 'bin', 'o']
def valid(f):
	p = f.find('.')
	tx = f[p+1:]
	return tx not in ext
	
def get_files(path):
	_all = get_all(path)
	all_files = []
	for f in _all:
		new_path = join(path, f)
		if isfile(new_path) and f[0]!='.' and valid(f):
			all_files.append(f)
	return all_files
	
def without_extension(name):
	p = name.find('.')
	return name[0:p]
	
def remove_space(name):
	return name.replace(' ', '%20')


mypath = os.getcwd()
url = "https://github.com/mdturin/CodeRed/blob/master"
readme = open("README.md", "w")

readme.write("# CodeRed\n")
readme.write("Competetive Programming Algorithms & Data Structures\n")

	
def dfs(cur_path, path_name, depth):
	cur_dirs = get_dir(cur_path)
	for cur_dir in cur_dirs:
		readme.write(depth + '- ' + cur_dir + "\n")
		new_cur_path = join(cur_path, cur_dir)
		dfs(new_cur_path, path_name+"/"+cur_dir, depth+"\t")
	
	cur_files = get_files(cur_path)
	for f in cur_files:
		new_url = remove_space(url + "/" + path_name + "/" + f)
		ff = without_extension(f)
		readme.write(depth + '- ' + "[" + ff + "](" + new_url + ")\n")

def fun(all_dir):
	new_dir = []
	for d in all_dir:
		if d[0:1].isdigit():
			new_dir.append(d)
	return new_dir

all_dir = get_dir(mypath)
all_dir = fun(all_dir)

for cur_dir in all_dir:
	cur_path = join(mypath, cur_dir)
	cur_files = get_files(cur_path)
	
	readme.write("\n")
	readme.write("## " + cur_dir + "\n")
	dfs(cur_path, cur_dir, '')
	
## https://github.com/mdturin/CodeRed/blob/master/Data%20Structure/Bit%20Range%20Query%20Point%20Update.cpp
