#pragma once
#include "glob_func.h"

class merging
{
	set<merging*> merged;

public:
	bool merge(merging* copy);
	bool demerge(merging* copy);

	//виконує якісь дії над усіма однаковими об'єктами, що пройшли об'єднання
	void for_merged(function<void(merging*)>);

protected:
	//вирізає свій об'єкт із списку однакових об'єктів, об'єднаних з ним - видаляє його адресу з контейнерів інших об'єктів 
	//та передає свій список однакових об'єктів у підпорядкування першому із свого списку
	void cut_me();

private:
	//bool merged_add(merging* same_unit);//додати до контейнеру однакових адрес
	//bool _merged_del(merging* same_unit);//видалити з контейнеру однакових адрес
	
	//виконує якісь дії над усіма однаковими об'єктами, що пройшли об'єднання
	void _for_merged(function<void(merging*)>, set<merging*>&);

	bool _find_in_my_merged(merging*);
	bool _find_in_all_merged(merging*);
	 
	//повертає контейнер адрес однакових об'єктів
	const set<merging*>& _get_same_units() const;
};

