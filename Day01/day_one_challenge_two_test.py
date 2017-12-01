import unittest
import captcha_calc

class TestCaptchas(unittest.TestCase):
    def test_all_matches(self):
        self.assertEqual(captcha_calc.solve_halfway_length_forward("1212"),6)

    def test_no_matches(self):
        self.assertEqual(captcha_calc.solve_halfway_length_forward("1221"),0)

    def test_single_match(self):
        self.assertEqual(captcha_calc.solve_halfway_length_forward("123425"),4)

    def test_scatteredmatches(self):
        self.assertEqual(captcha_calc.solve_halfway_length_forward("12131415"),4)


if __name__ == '__main__':
    unittest.main()