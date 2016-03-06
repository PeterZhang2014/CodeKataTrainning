/******************************************************************************************** 
 * Copyright (C) 2016/03/06 , Genvision
 *
 * File Name    : bowling.h
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
#ifndef __BOWLING_H__
#define __BOWLING_H__

#define SINGLE_GAME_FRAME_NUMBER   (10)

enum e_frameStatus {
	FRAME_STATUS_NORMAL = 0,
	FRAME_STATUS_STRIKE, /*一次全中*/
	FRAME_STATUS_SPARE,  /*补中*/
};

struct s_singleFrameInfo {
	unsigned int first_roll_number;
	unsigned int second_roll_number;
};

int single_roll_score(unsigned int number);
int single_frame_score(const unsigned int prev_frame_status, \
		const int first_roll_score, const int second_roll_score);
int single_game_score(struct s_singleFrameInfo *frame_array);
#endif //__BOWLING_H__
