# build option variables

bld = 0 # 0 = test; 1 = release
env = 1 # 0 = c++; 1 = c++ & sfml

# build location variables

varSrc0 = 'src'

varObj0 = 'bld/test/'
varTrg0 = 'bin/test/'

varObj1 = 'bld/release/'
varTrg1 = 'bin/release/'

trg = 'app'

libs = ['sfml-window', 'sfml-graphics', 'sfml-system']
libpath = ['lib/SFML-2.5.1/lib']

tmpTrg = ""
tmpSrc = ""

# build environment variables

env0 = Environment(CCFLAGS = '-std=c++11 -pthread')
env1 = Environment(CCFLAGS = '-std=c++11 -pthread -Ilib/SFML-2.5.1/include')

# build option if statements

if bld == 0:
    tmpTrg = varTrg0
    tmpSrc = varObj0
elif bld == 1:
    tmpTrg = varTrg1
    tmpSrc = varObj1

# add variantdir to srcFile strings

VariantDir(tmpSrc, varSrc0, duplicate = 0) # set object and source folder
trg = tmpTrg + trg # set target directory

# build source file lists
srcFiles = ['main.cpp']
src = [Glob(tmpSrc + '/base/*.cpp'), Glob(tmpSrc + '/basicUtils/*.cpp'), Glob(tmpSrc + '/entity/*.cpp'), Glob(tmpSrc + '/basicShape/*.cpp')]
#src = [Glob(tmpSrc + '/base/*.cpp'), Glob(tmpSrc + '/basicUtils/*.cpp'), Glob(tmpSrc + '/entity/*.cpp'), Glob(tmpSrc + '/basicShape/*.cpp'), Glob(tmpSrc + '/levelShape/*.cpp')]

for i in range(len(srcFiles)):
    src.append(tmpSrc + srcFiles[i])

if env == 0: # 0 = c++
    env0.Program(target = trg, source = src) # create program without sfml
elif env == 1: # 1 = c++ & sfml
    env1.Program(target = trg, source = src, LIBS = libs, LIBPATH = libpath) # create program with sfml
