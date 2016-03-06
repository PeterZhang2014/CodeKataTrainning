/******************************************************************************************** 
 * Copyright (C) 2016/03/06 , Genvision
 *
 * File Name    : test_main.c
 * File Mark    :
 * Description  : 
 * Verision     : 1.0
 * Date         : Mar 06, 2016
 * Author       : Peter Zhang
 * Email        : zfy31415926.love@163.com OR zhangfy@genvision.cn
 *
 * History 1    :
 *    Date      :
 *    Version   :
 *    Author    :
 *    Modification :
 * History 2    : ...
 ********************************************************************************************/
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmockery.h>
#include <bowling.h>

/****************************************************************************
 *                             data types define                            *
 ****************************************************************************/

/****************************************************************************
 *                               Global Variable                            *
 ****************************************************************************/

/****************************************************************************
 *                            Function Define                               *
 ****************************************************************************/
void test_single_roll_score(void **state)
{
	assert_int_equal(single_roll_score(0),0);
	assert_int_equal(single_roll_score(6),6);
	assert_int_equal(single_roll_score(-2),-1);
	assert_int_equal(single_roll_score(32),-1);
}
void test_single_frame_score(void **state)
{
	assert_int_equal(single_frame_score(FRAME_STATUS_NORMAL,5,5),10);
	assert_int_equal(single_frame_score(FRAME_STATUS_STRIKE,5,4),18);
	assert_int_equal(single_frame_score(FRAME_STATUS_STRIKE,5,0),10);
	assert_int_equal(single_frame_score(FRAME_STATUS_SPARE,6,4),16);
	assert_int_equal(single_frame_score(FRAME_STATUS_SPARE,7,0),14);
	assert_int_equal(single_frame_score(4,5,5),-1);
}
void test_single_game_score(void **state)
{
	struct s_singleFrameInfo array_1[SINGLE_GAME_FRAME_NUMBER] = {
		{3,7},
		{5,5},
		{2,3},
	};
	assert_int_equal(single_game_score(array_1),10+5+10+2+5);
	
	struct s_singleFrameInfo array_2[SINGLE_GAME_FRAME_NUMBER] = {
		{3,7},
		{5,5},
		{2,3},
		{10,0},
		{4,2},
		{0,10},
		{3,5},
	};
	assert_int_equal(single_game_score(array_2),10+5+10+2+5+10+6+6+10+3+8);
}
/* name        : main 
 * param       : 
 * function    : only for test
 * return      : 
 * author      : Peter Zhang
 * date        : Mar 06,2016
 */
int main(int argc, const char *argv[])
{
	const UnitTest tests[] = {
		unit_test(test_single_roll_score),
		unit_test(test_single_frame_score),
		unit_test(test_single_game_score),
	};
	
	return run_tests(tests);
}
