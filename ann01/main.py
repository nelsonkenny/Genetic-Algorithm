from ann01 import *

def main():
  weight_file = open("weights.in","r")
  pattern_file = open("patterns.in", "r")
  nn_obj = Network(weight_file, pattern_file)
  nn_obj.read_patterns()
  nn_obj.read_weights()
  nn_obj.scale_pattern_values()
  nn_obj.calculate_outputs() 
  nn_obj.write_output()

main()