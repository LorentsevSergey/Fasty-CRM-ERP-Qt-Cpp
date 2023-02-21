#pragma once
#include "merging.h"
#include "state.h"

class base_unit : public merging {
	//set of pointers to the objects refers to me
	//I will send my updates to them
	set<base_unit*> s_what_links_to_me;

	//set of pointers to the objects I link to
	//I will get updates from them
	set<base_unit*> s_i_link_to;

public:
	base_unit() {}

	//base_unit(base_unit* what_links_to_me);

	//зв'язує з об'єктом, котрому будуть надсилатись оновлення з мого об'єкту
	bool will_send_upds_to(base_unit* what_links_to_me);

	//розриває зв'язок з об'єктом, щоб не надсилати йому оновлень із свого об'єкту
	bool will_not_send_upds_to(base_unit* what_links_to_me);

	void my_data_is_updated();

	state state;

protected:
	~base_unit();

private:
	//отримання даних з об`екту, на котрий я посилаюсь
	//реалізація: порівняня отриманої адреси з наявними, зчитування даних з неї, обробка згідно функціоналу, передача оновлення далі
	virtual void _get_update_from(const base_unit*) = 0;
};