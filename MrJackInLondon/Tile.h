#pragma once
class CTile
{
public:
	/*
	const int i_valid;
	const int i_num;
	const int i_type;
	*/
	CTile();
	CTile(int pos, int type, int valid);
	CPoint p_tilepos;
	int i_valid_m, i_num_m, i_type_m;
	int i_default_item;
	bool onLight;
	bool b_lamp_on;
	bool b_checkpoint_on;
	bool b_manhole_on;
	/*
	type 0 장애물
	type 1 일반 타일(길)
	type 2 가스등
	type 3 맨홀
	type 4 검문소
	*/
	int i_Item_on;
	/*
	0 nothing
	1 Lamp
	2 Manhole
	3 Shelock
	4 Watson
	5 Smith
	6 Lestrade
	7 Stealthy
	8 William
	9 Goodley
	10 Jeremy
	ex1) manhole & Smith = 52
	ex2) manhole & Jeremy = 102
	*/
	void setTile(CPoint pos_2d, int type, int valid);
	
	void setItem(int value) {
		this->i_Item_on = value;
		this->i_default_item = value;
	}
	void checkPos();
	void swapItem(CTile& old_tile);
};
