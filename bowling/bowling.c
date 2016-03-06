/******************************************************************************************** 
 * Copyright (C) 2016/03/06 , Genvision
 *
 * File Name    : bowling.c
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
#include <stdio.h>
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
/* name        : single_roll_score 
 * param       : the number of the bottles hit every time 
 * function    : 
 * return      : 
 * author      : Peter Zhang
 * date        : Mar 06,2016
 */
int single_roll_score(unsigned int number)
{
	if (number < 0 || number > 10)
	{
		return -1;
	}
	else
	{
		return (number*1);
	}
}
/* name        : single_frame_score 
 * param       :  
 * function    : 
 * return      : 
 * author      : Peter Zhang
 * date        : Mar 06,2016
 */
int single_frame_score(const unsigned int prev_frame_status, \
		const int first_roll_score, const int second_roll_score)
{
	int frame_score = 0;
	switch(prev_frame_status)
	{
	case FRAME_STATUS_NORMAL:
		{
			frame_score = first_roll_score + second_roll_score;
			break;
		}
	case FRAME_STATUS_STRIKE:
		{
			frame_score = (first_roll_score + second_roll_score)*2;
			break;
		}
	case FRAME_STATUS_SPARE:
		{
			frame_score = first_roll_score*2 + second_roll_score;
			break;
		}
	default:
		{
			frame_score = -1;
			break;
		}
	}

	return frame_score;
}
/* name        : single_game_score 
 * param       :  
 * function    : 
 * return      : 
 * author      : Peter Zhang
 * date        : Mar 06,2016
 */
int single_game_score(struct s_singleFrameInfo *frame_array)
{
	int score = 0;

	if (frame_array == NULL)
	{
		return -1;
	}

	int i = 0;

	for (i = 0; i < SINGLE_GAME_FRAME_NUMBER; i ++)
	{
		unsigned int number = frame_array[i].first_roll_number + frame_array[i].second_roll_number;
		if (number > 10)
		{
			return -1;
		}
	}

	int frame_status = FRAME_STATUS_NORMAL;

	for (i = 0; i < SINGLE_GAME_FRAME_NUMBER; i ++)
	{
		int first_score = single_roll_score(frame_array[i].first_roll_number);
		if (first_score == -1)
		{
			return -1;
		}
		int second_score = single_roll_score(frame_array[i].second_roll_number);
		if (second_score == -1)
		{
			return -1;
		}

		int cur_frame_score = single_frame_score(frame_status, first_score, second_score);
		if (cur_frame_score == -1)
		{
			return -1;
		}

		score += cur_frame_score;

		if (first_score == 10)
		{
			frame_status = FRAME_STATUS_STRIKE;
		}
		else if ((first_score != 10) && (first_score + second_score == 10))
		{
			frame_status = FRAME_STATUS_SPARE;
		}
		else
		{
			frame_status = FRAME_STATUS_NORMAL;
		}
	}

	return score;
}
