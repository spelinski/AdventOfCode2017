def find_num_steps_exit(list_of_instructions, challengeTwo):
    instructions_as_ints = list(map(int, list_of_instructions))
    PC = 0
    steps = 0
    while PC < len(instructions_as_ints):
        if challengeTwo and (instructions_as_ints[PC] >= 3):
            instructions_as_ints[PC] -= 1
            PC += instructions_as_ints[PC] + 1
        else:
            instructions_as_ints[PC] += 1
            PC += instructions_as_ints[PC]-1
        steps += 1

    return steps

if __name__ == '__main__':
    file = open("challenge_input.txt", "r")
    my_instructions = file.readlines()
    print(find_num_steps_exit(my_instructions,False))
    print("challenge two")
    print(find_num_steps_exit(my_instructions,True))