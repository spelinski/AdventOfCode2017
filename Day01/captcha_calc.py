def get_list_of_numbers(captcha_string):
    return [int(x) for x in captcha_string]


def add_matching_items(list_of_ints, distance_of_compare):
    total = 0
    for index, value in enumerate(list_of_ints, start=0):
        compare_index = (index + distance_of_compare) % len(list_of_ints)
        if value == list_of_ints[compare_index]:
            total += value
    return total


def solve(captcha_string, distance_of_compare):
    list_of_ints = get_list_of_numbers(captcha_string)
    return add_matching_items(list_of_ints, distance_of_compare)


def solve_adjacent(captcha_string):
    return solve(captcha_string, 1)


def solve_halfway_length_forward(captcha_string):
    return solve(captcha_string, len(captcha_string)/2)
