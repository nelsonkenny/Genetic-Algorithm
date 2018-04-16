from math import exp

class Network: 
  def __init__(self, inputOne_file, inputTwo_file):
    self.weight_file = inputOne_file 
    self.pattern_file = inputTwo_file
    self.weight_info = [] # This array contains the number of nodes for the input and output layers
    self.pattern_info = [] # This array contains the number of patterns, the number of values per pattern, and the maximum value possible for these inputs
    self.weights = [] # This array contains the different weights for the neural network
    self.patterns = [] # This array contains the different input patterns 
    self.outputs = [] # This array contains the resulting outputs of the network when the input patterns are applied.

  def read_weights(self):
    '''This function is to read the values regarding the weights from the appropriate file'''
    self.weight_info = self.weight_file.readline().split()
    for val in self.weight_file: 
      self.weights.append(val.split())
  
  def read_patterns(self):
    '''This function is to read the values regarding the patterns from the appropriate file''' 
    self.pattern_info = self.pattern_file.readline().split()
    for val in self.pattern_file:
      self.patterns.append(val.split())
      
  def scale_pattern_values(self): 
    '''This function is to scale the pattern values so they could be between 0 and 1'''
    max_val = int(self.pattern_info.pop()) # This is the maximum value possible for the pattern inputs
    for i in range (int(self.pattern_info[0])): 
      for j in range(int(self.pattern_info[1])):  
        self.patterns[i][j] = float(self.patterns[i][j])/ max_val 
  
  def calculate_outputs(self):
    '''This method is to calculate the outputs of the neural network'''   
    for i in range(int(self.pattern_info[0])):  
      for j in range(int(self.pattern_info[1])):
        product_sum = 0
        product_sum += float(self.patterns[i][j])* float(self.weights[i][j]) # Multiply each pattern input by their corresponding weight and sum the products for each output layer
        output = self.sygmoid_function(product_sum)
        self.outputs.append(output)
   
  def sygmoid_function(self, x):
    '''This method is to apply the sygmoid function to the product sum of each output layer'''
    output = 1/(1+exp(-x))
    return output


  def write_output(self):
    '''This method is to write the outputs of the neural network in a text file '''
    output_file = open("output_file.in","w")
    output_file.write(str(self.weight_info[0]) + " Patterns ")
    for i in range(int(self.weight_info[0])):
      output_file.write("Output " + str(i)+": ")
      output_file.write(str(self.outputs[i]))
      output_file.write(" ")
      
    
