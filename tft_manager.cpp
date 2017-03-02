#include <algorithm>
#include "tft_manager.h"

/*
 * refreshFunction:
 *	called by for_each
 *********************************************************************************
 */
void refreshFunction(TFT_field* p)
{
	p->refresh();
}

/*
 * TFT_manager:
 *	Constructor of the class
 *********************************************************************************
 */
TFT_manager::TFT_manager()
{

}


/*
 * add:
 *	add new field to the list
 *********************************************************************************
 */
void TFT_manager::add(TFT_field* field)
{
	_field_list.push_back(field);

}

/*
 * refresh:
 *	loop through the list and refresh all elements
 *********************************************************************************
 */
void TFT_manager::refresh()
{
	for_each(_field_list.begin(), _field_list.end(), refreshFunction);
}