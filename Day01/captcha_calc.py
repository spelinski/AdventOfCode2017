import argparse

def solve(captcha_string):
    list_of_ints = [ int(x) for x in captcha_string]
    return add_matching_items(list_of_ints)


def add_matching_items(list_of_ints):
    total = 0
    for index,value in enumerate(list_of_ints,start=0):
        compare_index = 0 if index == (len(list_of_ints)-1) else index+1
        if value == list_of_ints[compare_index]:
            total += value
    return total


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Process a captcha')
    parser.add_argument('captcha_string', metavar="captcha", nargs=1, help='A captcha to process')
    args = parser.parse_args()
    print(solve(args.captcha_string))
