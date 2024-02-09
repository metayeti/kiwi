################################################################################
#
#  svg2code utility
#  (for kiwi)
#
#  ---
#
#  This utility converts a SVG file to a C++ string appropriately formatted for
#  inclusion into svg_resources.h.
#
#  Usage: python svg2code.py [constant name] [input file] | clip
#
################################################################################

import fileinput
import sys

outputFormat = 'const char* const {varName} = "{data}";'

def readTextFile(filename):
	data = ''
	with open(filename, 'r') as file:
		data = (file.read()
			.replace('<!-- Created with Inkscape (http://www.inkscape.org/) -->\n', '')
			.replace('\\', '\\\\')
			.replace('"', '\\"')
#			.replace('\n', '\\n'))
			.replace('\n', ''))
	return data

if __name__ == '__main__':
	if len(sys.argv) < 3:
		sys.stdout.write('Usage: {util} [constant name] [input file]\n'.format(util = sys.argv[0]))
		sys.exit(0)

	inputFilename = sys.argv[2]
	output = outputFormat.format(varName = sys.argv[1], data = readTextFile(inputFilename))
	sys.stdout.write(output)
