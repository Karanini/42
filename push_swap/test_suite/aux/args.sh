

# Error
TEST_ARGS_1=(
	$'a'
	$'/dev/null'
	$'super test' 
	$'-'
	$'+'
	$'--'
	$'-+'
	$'++'
	$'   -  '
	$'         + '
	$'(1 2 3)'
	$'{1 2 3}'
	$'[1 2 3]'
	$'0$ 1 2'
	$'0 1# 2 3'
	$'1 2 3@ 4 5 6'
	$'0 1! 2'
	$' 8 9 10 11% 4'
	$'&1 2 3'
	$'1 | 2'
	$'0x01'
	$'0a'
	$'1b11'
	$'111b'
	$'-1 -2 -3 -4 144a 2 3 4 5 6'
	$'0b1 2 3 4'
	$'0 1 2 x 3'
	$'7F 1 2 3'
	$'0h44 5 6'
	$'4 -'
	$'5-'
	$'6 7+'
	$'8 + 11'
	$'8 - 12'
	$'16   2 3 +'
	$'1 -- 3'
	$'4 5 ++ 6'
	$'1 --2 3 4 5 6'
	$'1 2 3 ++4 5 6'
	$'7 8 +-9 10'
	$'11 12 -+13 14'
	$'1++ 3 4'
	$'2-- 3 4'
	$'0 0' 
	$'0 +0' 
	$'0 -0' 
	$'00 0' 
	$'-0 +0' 
	$'3 +2 +3'
	$'01 00001'
	$'-01 -0001'
	$'+01 +0001'
	$'1 002 4 12 02'
	$'-10 5 0 1 2 3 4 -10'
	$'4 5 6 4 3'
	$'3 111-2'
	$'4 ++5'
	$'3 --1 8'
	$'-1 12+2'
	$'-2147483649'
	$'2147483648'
	$'3 -18446744073709551618 2' 
	$'99999999999999999999999999'
	$'999999999999999999999999999999999'
	$'2147483648-2'
	$'-2147483648+2'
	$'0000000000000000000000000000000000000000000000001 0001'
	$'4 1.0 2 3'
	$'1 2 3.1'
	$' 1 2 .6'
	$'1 . 2'
	$' 1 2 \x0C   3'
	$'1 2 3\x0C'
	$' 1 2 \x0B   3'
	$'1 2 3\x0B'
	$'		1	'
	$'		-2147483648		'
	$'1	6	3'
	$'	1	6	3'
	$'	1	6	3	'
	$'1	6	3	'
	$'3 				'
	$' 	3 				'
	$' 5 	'
	$'	6 7'
	$'8 9 	'
)


TEST_ARGS_2=(
	$'1 2'
	$'1 2 '
	$' 1 2'
	$'-1 0 1'
	$'    1 2    '
	$'    1            2          '
	$'       4      2      1                      3  0    '
	$'                                                 3 6      7'
	$'2147483647 3 6             '
	$'   2147483647       2147483646'
	$'-2147483648'
	$'-2147483645                                                     '
	$'  12 -2147483648'
	$'    2147483647 -2147483648'
)


TEST_ARGS_3=(
	
)


# OK
TEST_ARGS_4=(
	$'1 2'								$'\x04'
	$'1 2 '								$'\x04'
	$' 1 2'								$'\x04'
	$'-1 0 1'							$'ra\nrra'
	$'    1 2    '						$'\x04'
	$'    1            2          ' 	$'\x04'
	$'2147483646 3 6             '		$'ra'
	$'   2147483647       2147483646'	$'sa'
	$'-2147483648'						$'\x04'
	$'  12 -2147483648'					$'rrr'
	$'    2147483647    -2147483648  '	$'sa'
	$'    2147483647 -2147483648'		$'ra'
	$'    2147483647 -2147483648  '		$'rra\nra\nsa'
	$'  2147483647   -2147483648 '		$'pb\npb\nrb\npa\npb\nrrr\nrrr\nrrb\nrrb\npa\npa'
	$'1   2 3 4'						$'ra\nra\nra\nra'
	$'1 2   3 4'						$'sa\nsa'
	$'1 2 3   4 '						$'sa\nsa'
	$'1 2 3 4   '						$'ra\nra\nra\nra\nra\nra\nra\nra'
	$' 2147483644 2147483646   '		$'pb\npa'
	$'  02 3   '						$'rrb'
	$'  250000000   4'					$'ra\nrrr\nsb\nss\nrr\nsa'
	$'  350000000'						$'rb'
	$'  450000000'						$'rr'
	$'  550000000'						$'pa'
	$'  1 2 3   4 0'					$'pa\npa\npa\npa\nsb\nsb\nsb\nsb\nrrb\nrrb\nrrb\nrrb\nrra'
	$'1 2 3   '							$'pb\npb\npb\nra\nra\nsa\nrra\nrra\nrra\npb\npb\npa\npa\npa'
)

# KO
TEST_ARGS_5=(
	$'1 2 3 4'							$'sa'
	$'2 1'								$'pa'
	$'1 2 3 4 5 6 7'					$'pb\nrb'
	$'7 1 2 3 4 5 6'					$'pb'
	$'0'								$'pb'
	$'1 2 3 4'							$'sa\npb\npb\nsb\nrb\npa\npa'
	$'1 2 3 4 5 6 7 -1'					$'\x04'
)

# Error
TEST_ARGS_6=(
	$'2 1'				$'sa '
	$'2 1'				$'saa'
	$'2 1 0'			$'	'
	$'1 2 0'			$'\n\npb\npa'
	$'2 1'				$'rrrr'
	$'1 2 3 4'			$'/dev/null'
	$'1 2 3 4'			$'saa\nsa'
	$'2 1'				$'ok'
	$'1 2 3'			$'lol'
	$'1 2 3 4'			$'sbb\nsa'
	$'1 2 3 4'			$'sss\nsa'
	$'1 2 3 4'			$'ss\nss\nss\nss\n+'
	$'1 2 3 4'			$'ss\nss\nss\n ss'
	$'1 2 3 4'			$'ra\nrar\nra\nrar\nra'
	$'1 2 3 4'			$' ss\nss'
)