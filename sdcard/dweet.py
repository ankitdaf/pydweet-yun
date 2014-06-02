#
# Code by
# Ankit Daftery
# June 2, 2014
# 
# This code is licensed under the GPL v3 license.
# You may use the code and modify it freely
# All modifications and improvements must be shared under the GPL v3 license
# This code cannot be used with hardware that forbids software alterations
#
# A simple Python wrapper to talk to Dweet.io
# Use an up-to-date version of the Requests library
# 
# Usage :
# 
# Get : python dweet.py guid get
#
# Post : python dweet.py guid post "{'sensor1':'0','sensor2':'1'}"
# 
# 

import requests
import sys

url = "https://dweet.io:443/"
guid = ''
post_path = "dweet/for/"
get_path = "get/latest/dweet/for/"

def get_dweet(guid):
	r = requests.get(url+get_path+guid).json()
	if (r['this']=='succeeded'):
		for item in r['with'][0]['content']:
			print str(item)+","+str(r['with'][0]['content'][item])
	else:
		print 'Fail'

def post_dweet(guid,payload):
	r = requests.post(url+post_path+guid,data=payload).json()
	if(r['this']=='succeeded'):
		print 'Success'
	else:
		print 'Fail'

if __name__ == '__main__':
	guid = sys.argv[1]
	if(sys.argv[2]=='get'):
		response = get_dweet(guid)
	if(sys.argv[2]=='post'):
		payload = eval(sys.argv[3])
		response = post_dweet(guid,payload)