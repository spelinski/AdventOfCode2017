import unittest
import captcha_calc

class TestCaptchas(unittest.TestCase):
    def test_two_middle_matches(self):
        self.assertEqual(captcha_calc.solve_adjacent("1122"),3)

    def test_four_ones(self):
        self.assertEqual(captcha_calc.solve_adjacent("1111"),4)

    def test_no_matches(self):
        self.assertEqual(captcha_calc.solve_adjacent("1234"),0)

    def test_only_ends_matching(self):
        self.assertEqual(captcha_calc.solve_adjacent("91212129"),9)


if __name__ == '__main__':
    unittest.main()