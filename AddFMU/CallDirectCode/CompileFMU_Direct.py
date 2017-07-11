# Import the compiler function
from pymodelica import compile_fmu

# Specify Modelica model and model file (.mo or .mop)
# SimpleC is the name of the .mo file and function name
model_name = "CallDirect"
mo_file = "CallDirect.mo"

# Compile the model and save the return argument, for use later if wanted
# my_fmu = compile_fmu(model_name, mo_file, target="cs", compiler_options = {'extra_lib_dirs':'C:/Users/justin.shultz/Dropbox/FMU/Passing_Data_Testing'})
my_fmu = compile_fmu(model_name, mo_file, target="cs",compiler_options = {'extra_lib_dirs':'C:/Users/justin.shultz/Dropbox/FMU/Passing_Data_Testing/AddFMU'})