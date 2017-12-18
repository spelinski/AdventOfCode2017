import re
from collections import defaultdict

class Tower_builder():
    def __init__(self,list_of_programs):
        self.get_tuple_for_dicts_of_programs_and_values(list_of_programs)

    def get_tuple_for_dicts_of_programs_and_values(self,list_of_programs):
        self.dict_of_weights = {}
        self.dict_of_programs = {}
        for line in list_of_programs:
            sub_strings = re.split(r'\s+\-\>', line)
            sub_strings = [x.strip() for x in sub_strings]
            base_program_with_value = sub_strings[0].replace("(", "").replace(")", "").split(" ")
            self.dict_of_weights[base_program_with_value[0]]=int(base_program_with_value[1])
            if len(sub_strings) > 1:
                temp_list = sub_strings[1].split(",")
                temp_list = [x.strip() for x in temp_list]
                self.dict_of_programs[base_program_with_value[0]] = temp_list
        set_keys_to_pop = set()
        for key in self.dict_of_programs:
            for other_key in self.dict_of_programs:
                for program in self.dict_of_programs[other_key]:
                    if program == key:
                        if (key in self.dict_of_programs) and (other_key in self.dict_of_programs):
                            self.dict_of_programs[other_key].append({ key:self.dict_of_programs[key]})
                            set_keys_to_pop.add(key)
                            if key in self.dict_of_programs[other_key]: self.dict_of_programs[other_key].remove(key)
        for key in set_keys_to_pop:
            self.dict_of_programs.pop(key)

    def find_bottom(self):
        return next(iter(self.dict_of_programs))

    def find_sum_of_dict(self, input_dict):
        sum = 0
        for key in input_dict:
            sum += self.dict_of_weights[key]
            if type(input_dict[key]) is dict:
                print("time to dig")
            elif type(input_dict[key]) is list:
                sum += self.find_sum_of_list(input_dict[key])
            elif type(input_dict[key]) is str:
                print("value time")
            else:
                print("sorry")
        return sum

    def find_sum_of_list(self, input_list):
        sum = 0
        for item in input_list:
            if type(item) is dict:
                sum += self.find_sum_of_dict(item)
            elif type(item) is list:
                sum += self.find_sum_of_list(item)
            elif type(item) is str:
                sum += self.dict_of_weights[item]
            else:
                print("sorry")
        return sum

    def find_diff_of_program_dict(self):
        list_of_sums = []
        one_key_to_rule_them_all = next(iter(self.dict_of_programs))
        if type(self.dict_of_programs[one_key_to_rule_them_all]) is dict:
            print("i'm here")
        elif type(self.dict_of_programs[one_key_to_rule_them_all]) is list:
            for item in self.dict_of_programs[one_key_to_rule_them_all]:
                if type(item) is dict:
                    list_of_sums.append((self.find_sum_of_dict(item),item))
                elif type(self.dict_of_programs[one_key_to_rule_them_all][0]) is list:
                    print ("even deeper")
                elif type(self.dict_of_programs[one_key_to_rule_them_all][0]) is str:
                    print ("value time")
                else:
                    print ("oops")
        elif type(self.dict_of_programs[one_key_to_rule_them_all]) is str:
            print("woop woop")
        else:
            print("oops")
        for item in list_of_sums[1:]:
            if list_of_sums[0][0] > item[0]:
                found,value = self.walk_for_problems(item)
                if found: return value
                found, value = self.walk_for_problems(list_of_sums[0])
                if found: return value
                print("greater")
                print(list_of_sums[0])
                print(item)
                return self.dict_of_weights[next(iter(list_of_sums[0][1]))] - (list_of_sums[0][0] - item[0])
            elif list_of_sums[0][0] < item[0]:
                found, value = self.walk_for_problems(item)
                if found: return value
                found, value = self.walk_for_problems(list_of_sums[0])
                if found: return value
                print(list_of_sums[0])
                print(item)
                return self.dict_of_weights[next(iter(item[1]))] - (item[0] - list_of_sums[0][0])
                #return self.dict_of_weights[next(iter(list_of_sums[0][1]))] + (item[0] - list_of_sums[0][0])


    def get_weight_needed(self):
        #print(self.dict_of_programs)
        return self.find_diff_of_program_dict()

if __name__ == '__main__':
    file = open("challenge_one_input.txt", "r")
    my_programs = file.readlines()
    file.close()
    my_tower_builder = Tower_builder(my_programs)
    print(my_tower_builder.find_bottom())
    print(my_tower_builder.get_weight_needed())