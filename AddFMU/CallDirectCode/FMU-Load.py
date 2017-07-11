# Simulation of IOTest.FMU
# Import load_fmu from pyfmi
from pyfmi import load_fmu
import numpy as np
# from pyjmi.common.plotting import plot_gui # or pyfmi.common.plotting import plot_gui
import matplotlib.pyplot as plt

modelName = 'CallDirect'
numSteps = 1000
timeStop = 20


# Load FMU created with the last script
myModel = load_fmu(modelName+'.fmu')

# Load options
opts = myModel.simulate_options()

# Set number of timesteps
opts['ncp'] = numSteps

# Change parameter value
# d_new = myModel.get('d')
# myModel.set('d',d_new)

# Set up input, needs more than one value to interpolate the input over time. 
t = np.linspace(0.0,timeStop,numSteps)
u1 = np.sin(t)
print 'The Length of u1 is: ', len(u1)
u2 = np.empty(len(t)); u2.fill(5.0)
print 'The Length of u2 is: ', len(u2)
u_traj = np.transpose(np.vstack((t,u1,u2)))
print 'The Shape of the Input is: ', u_traj.shape
input_object = (['FirstInput','SecondInput'],u_traj)

# Internalize results
res = myModel.simulate(final_time=timeStop, input = input_object, options=opts)
# res = myModel.simulate(final_time=timeStop, input = input_object)
# print 'res: ', res

# Internalize individual results
FMUTime = res['time']
FMUIn1 = res['FirstInput']
FMUIn2 = res['SecondInput']
FMUOut = res['FMUOutput']

print 'The Length of FMUTime is: ', len(FMUTime)
print 'The Length of FMUIn1 is: ', len(FMUIn1)
print 'The Length of FMUIn2 is: ', len(FMUIn2)
print 'The Length of FMUOut is: ', len(FMUOut)

# results = np.transpose(np.vstack((t,FMUIn1,FMUIn2,FMUOut)))

# Print results
# print 'FMUTime', FMUTime
# print 'FMUIn1: ', FMUIn1
# print 'FMUIn2: ', FMUIn2
# print 'FMUOut: ', FMUOut

# plt.figure(1)
# u1Plot = plt.plot(t,u1,label='u1')
# u2Plot = plt.plot(t,u2,label='u2')
# plt.grid(True)
# plt.legend()
# plt.xlabel('time [s]')
# plt.show()

plt.figure(2)
# FMUIn1Plot = plt.plot(t,FMUTime[1:],label='FMUTime')
# FMUIn1Plot = plt.plot(t,FMUIn1[1:],label='FMUIn1')
# FMUIn1Plot = plt.plot(u1,FMUIn1[1:],label='FMUIn1')
# ModelInput = plt.plot(t,u1,label='t vs u1')
FMUIn1Plot = plt.plot(FMUTime,FMUIn1,label='FMUIn1')
# FMUIn2Plot = plt.plot(t,FMUIn2[1:],label='FMUIn2')
FMUIn2Plot = plt.plot(FMUTime,FMUIn2,label='FMUIn2')
# FMUIn2Plot = plt.plot(u2,FMUIn2[1:],label='FMUIn2')
# FMUOutPlot = plt.plot(t,FMUOut[1:],label='FMUOut')
FMUOutPlot = plt.plot(FMUTime,FMUOut,label='FMUOut')
# plt.plot(t,results[1],t,results[2],t,results[3])
plt.grid(True)
plt.legend()
# plt.ylabel('FMU time [s]')
plt.xlabel('time [s]')
plt.show()

# plot_gui.startGUI(modelName+'_result.txt')