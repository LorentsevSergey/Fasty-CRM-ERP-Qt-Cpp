#pragma once
#include "testing.h"
#include "ush.h"

void testing()
{
    srand(unsigned int(time(NULL)));
    const bool isShort = 1 ; //швидкий тест (1) чи повний (0)
    const size_t count = 1000000 ; //кількість об'єктів для тестування
    
    //test_state();
    //test_collect();
    //test_product_part();
    //test_storage();
    //test_product();
    test_property();
    //test_element(isShort, count);
    //test_cuboid_size(isShort, count);
    //test_merge(isShort);
    //test_change_data(isShort);
    //test_user();
    //type_size();
}

void test_state()
{
    product s;

    cout << s.state << endl;

    cout << "Change: ";
    s.state.changing();
    s.state.changed();
    cout << (s.state.is_changed() ? "yes" : "no") << endl;

    cout << "Delete: ";
    s.state.deleting();
    s.state.deleted();
    cout << (s.state.is_deleted() ? "yes" : "no") << endl;
}

void test_collect()
{
    const box_size
        bs0({ 0,0,0 }),
        bs1({ 10,10,10 }),
        bs2({ 20,20,20 }),
        bs3({ 30,30,30 }),
        bs4({ 40,40,40 }),
        bs5({ 50,50,50 }),
        bs6({ 60,60,60 }),
        bs7({ 70,70,70 }),
        bs8({ 80,80,80 }),
        bs9({ 90,90,90 });
    
    const storage_type  
        st0{ bs0, 0, 0 },
        st1{ bs1, 1, 10 },
        st2{ bs2, 2, 20 },
        st3{ bs3, 3, 30 },
        st4{ bs4, 4, 40 },
        st5{ bs5, 5, 50 },
        st6{ bs6, 6, 60 },
        st7{ bs7, 7, 70 },
        st8{ bs8, 8, 80 },
        st9{ bs9, 9, 90 };

    const storage
        s0{ "Box0", st0 },
        s1{ "Box1", st1 },
        s2{ "Box2", st2 },
        s3{ "Box3", st3 },
        s4{ "Box4", st4 },
        s5{ "Box5", st5 },
        s6{ "Box6", st6 },
        s7{ "Box7", st7 },
        s8{ "Box8", st8 },
        s9{ "Box9", st9 },
        s10{ "Box10", st0 },
        s11{ "Box11", st1 },
        s12{ "Box12", st2 },
        s13{ "Box13", st3 },
        s14{ "Box14", st4 },
        s15{ "Box15", st5 },
        s16{ "Box16", st6 },
        s17{ "Box17", st7 },
        s18{ "Box18", st8 },
        s19{ "Box19", st9 };

    dict.s.add(s0);
    dict.s.add(s1);
    dict.s.add(s2);
    /*dict.s.add(s3);
    dict.s.add(s4);
    dict.s.add(s5);
    dict.s.add(s6);
    dict.s.add(s7);
    dict.s.add(s8);
    dict.s.add(s9);
    dict.s.add(s10);
    dict.s.add(s11);
    dict.s.add(s12);
    dict.s.add(s13);
    dict.s.add(s14);
    dict.s.add(s15);
    dict.s.add(s16);
    dict.s.add(s17);
    dict.s.add(s18);
    dict.s.add(s19);*/


    cout << dict.bs << "\n\n";

    //filter f(dict.st.at(1), dict.st.at(1));
    //dict.st.filter(f).at(0)->set_weight(5);

    dict.bs.at(1).set({ { 9,9,9 } });

    //cout << dict.st << endl;






}

void test_product_part()
{
    //product prod;
    //prod.setrectangle_size({ 2, 3, 1 });
    //prod.setBruttoWeight(3);

    //storage stor;
    //stor.set_name("MyStorage");
    //stor.setrectangle_size({ 3,4,3 }, { 6,4,8 });
    //stor.setWeight(2);
    //stor.setMaxNetWeight(11);

    //product_part part(prod, 3, stor);
    //part.set_count(11);

    ////product_part* pp{ static_cast<product_part*>(*prod.getproductParts().begin()) };
    //cout << part << endl /*<< endl << *pp << endl << endl*/;

    //prod.setBruttoWeight(2);
    //part.set_count(10);
}

void test_storage()
{
    /*const box_size bs{ {1,2,3}, {4,5,6} };
    const storage_type st{ "15 kg", bs, 2, 15 };
    
    storage s{ "Small box" , st };
    const size_t i = reg.set_storage_type(st, &s);

    cout << s.get_full_name() << endl << s << endl;

    cout << "\n\nВстановлення нової макс ваги: ";
    reg.get_storage_type(i).set_max_net_weight(25);

    cout << "\n\nВстановлення нової назви типу: ";
    reg.get_storage_type(i).set_name("25 kg");*/

}

void test_product()
{
    product prod;
    //storage stor1(&prod);
    //storage stor2;
    //cout << stor1 << endl << stor2 << endl << endl;
    //prod.set_storage(stor2);

    //stor1.set_name("stor1");
    //stor1.set_count(5); //першим Count не буде встановлений - лише після MaxCount
    //stor1.setMaxCount(6);
    //stor1.setrectangle_size({ 2, 3, 4 }, { 5, 6, 7 });

    //stor2.set_name("stor2");
    //stor2.setMaxCount(7);
    //stor2.set_count(2); //нормально встановиться, бо після MaxCount
    //stor2.setrectangle_size({ 12, 13, 14 }, { 15, 16, 17 });
    
    //cout << endl << stor1 << endl << stor2 << endl;


    //stor.set_name("storage 0");
    //stor.count_plus(4);
    //cout << stor << endl;

    //stor.set_name("storage 1");
    //stor.count_plus(2);
    //cout << stor << endl;

    //stor.set_name("storage 2");
    //stor.count_plus(-2);
    //cout << stor << endl;

    //stor.set_name("storage 3");
    //stor.count_plus(-10);
    //stor.set_count(-3);
    //cout << stor << endl;
}

void test_property()
{
    property_type pt(property_type::val_t::STR);
    pt.set_name("test");

    ind i = dict.prop_t.add(pt);


    Property p(i);
    p.set("000");
    
    cout << "Index of prop_t in dict: " << i 
        << "\nType of property:\t" << p.my_type().get_type() 
        << "\nData:\t\t\t" << p.get().front() << endl;
}

bool test_element(bool isShort, size_t count)
{
    element<ush> a(0), b(1);
    vector<element<ush>> v;
    v.resize(count);
    timer t;

    cout << "count: " << count << "\nsize: " << v.size() << "\n\n";

    for (size_t i = 0; i < v.size(); ++i) { v[i] = rand() % 10; }
    cout << "\n\nsize: " << v.size() << endl;


    cout << "\nStart of merging\n";
    for (size_t i = 0; i < v.size(); ++i) a.merge(&v[i]);
    cout << "Merged\n";


    cout << "Start of getting\n";
    deque<ush> res;
    a.get(res);
    cout << "End of getting\n\n";


    /*for (auto i : res)
        cout << i;*/
    cout << "\nsize " << res.size() << "\n\n";


    cout << "elapsed time: " << t.elapse() << " milliseconds";
    return 1;
}

void test_cuboid_size(bool isShort, size_t count)
{
    ush l, w, h;
    string res = "OK";

    cout << "\ntest_cuboid_size:";
    for (size_t i = 0; i < count; ++i)
    {
        l = rand() % 100 + 1,
        w = rand() % 100 + 1,
        h = rand() % 100 + 1;
        if (test_cuboid_size_help(l, w, h))
        {
            if (!isShort) cout << "\n# " << i << "\tOk";
        }
        else
        {
            res = "error";
            cout << "\n# " << i << "\terror!\t(l=" << l << "\tw=" << w << "\th=" << h << ")";
        }
    }
    cout << (isShort ? " " : "\ncuboid_size ") << res << endl;
}
bool test_cuboid_size_help(ush l , ush w, ush h)
{
    cuboid_size size1 (l, w, h), size2;
    //cout << endl << size1;
    return
        size1.get_length() == l &&
        size1.get_width() == w &&
        size1.get_height() == h &&
        size1.get_volume() == l * w * h &&
        size2.set(l, w, h);
}

void test_merge(bool isShort)
{
    const int elem_count = 10;
    element<int> int_el[elem_count];

    for (int i = 0; i < elem_count; ++i)
        int_el[i] = i;

    cout << endl << "Print int_el[0] до объедиения" << endl;
    print_elements(int_el[0]);
    cout << endl;

    cout << endl << "Print int_el[4] до объедиения" << endl;
    print_elements(int_el[4]);
    cout << endl;

    cout << endl << "Print int_el[8] до объедиения" << endl;
    print_elements(int_el[8]);
    cout << endl;

    cout << "================ Начало объединения! ================" << endl;

    for (int i = 8; i < elem_count; ++i)
        cout << endl << "Объединение int_el[4] и int_el[" << i << "]: " << (int_el[4].merge(&int_el[i]) ? "Ok" : "Error!");

    cout << endl;

    for (int i = 1; i < elem_count; ++i)
        cout << endl << "Объединение int_el[0] и int_el[" << i << "]: " << (int_el[0].merge(&int_el[i]) ? "Ok" : "Error!");

    cout << endl << endl << "================ Окончание объединения! ================" << endl;


    cout << endl << "Print int_el[0] до разделения" << endl;
    print_elements(int_el[0]);
    cout << endl;

    cout << endl << "Print int_el[4] до разделения" << endl;
    print_elements(int_el[4]);
    cout << endl;

    cout << endl << "Print int_el[8] до разделения" << endl;
    print_elements(int_el[8]);


    cout << endl << endl << "================ Начало разделения! ================" << endl;


    cout << endl << "Разделение int_el[0] и int_el[1]: " << (int_el[0].demerge(&int_el[1]) ? "Ok" : "Error!") << endl;
    cout << endl << "Print int_el[0] после разделения" << endl;
    print_elements(int_el[0]);
    cout << endl << "Print int_el[1] после разделения" << endl;
    print_elements(int_el[1]);

    cout << endl << "Разделение int_el[4] и int_el[0]: " << (int_el[4].demerge(&int_el[0]) ? "Ok" : "Error!") << endl << endl;
    cout << endl << "Print int_el[0] после разделения" << endl;
    print_elements(int_el[0]);
    cout << endl << "Print int_el[4] после разделения" << endl;
    print_elements(int_el[4]);

    cout << endl << "Разделение int_el[0] и int_el[8]: " << (int_el[0].demerge(&int_el[8]) ? "Ok" : "Error!") << endl << endl;
    cout << endl << "Print int_el[0] после разделения" << endl;
    print_elements(int_el[0]);
    cout << endl << "Print int_el[8] после разделения" << endl;
    print_elements(int_el[8]);

    cout << endl << endl << "================ Окончание разделения! ================" << endl;
}

void test_change_data(bool isShort)
{
    //product product;
    //storage storage;
    //user u;

    //product.set_storage(storage);


    ////product.AddCountToStorage(11, storage);
    ////product.AddCountToStorage(43, storage);
    ////storage.set_count(9);
    ////storage.AddCount(0);

    //storage.set_name("Warehouse #1");
}

void test_user()
{
}

inline void type_size()
{
    cout << "\n======== Type Sizes ========\n\n";

    cout << "bool:\t\t\t"           << sizeof(bool)             << " bytes" << endl;        // 1 byte
    cout << "char:\t\t\t"           << sizeof(char)             << " bytes" << endl;        // 1 byte       -128 ... 127
    cout << "unsigned char:\t\t"    << sizeof(unsigned char)    << " bytes" << endl;        // 1 byte       0 ... 255
    cout << "wchar_t:\t\t"          << sizeof(wchar_t)          << " bytes" << endl;        // 2 bytes      -32 768 ... 32 767
    cout << "char16_t:\t\t"         << sizeof(char16_t)         << " bytes" << endl;        // 2 bytes      -32 768 ... 32 767
    cout << "char32_t:\t\t"         << sizeof(char32_t)         << " bytes" << "\n\n";      // 4 bytes      -2 147 483 648 ... 2 147 483 647

    cout << "short:\t\t\t"          << sizeof(short)            << " bytes" << endl;        // 2 bytes      -32 768 ... 32 767
    cout << "unsigned short:\t\t"   << sizeof(unsigned short)   << " bytes" << endl;        // 2 bytes      0 ... 65 535
    cout << "ush:\t\t\t"            << sizeof(ush)              << " bytes" << endl;        // 2 bytes      0 ... 65 535
    cout << "int:\t\t\t"            << sizeof(int)              << " bytes" << endl;        // 4 bytes      -2 147 483 648 ... 2 147 483 647
    cout << "unsigned int:\t\t"     << sizeof(unsigned int)     << " bytes" << endl;        // 4 bytes      0 ... 4 294 967 295
    cout << "uint:\t\t\t"           << sizeof(uint)             << " bytes" << endl;        // 4 bytes      0 ... 4 294 967 295
    cout << "size_t:\t\t\t"         << sizeof(size_t)           << " bytes" << "\n\n";      // 8 bytes      0 ... 18 446 744 073 709 551 615

    cout << "long:\t\t\t"           << sizeof(long)             << " bytes" << endl;        // 4 bytes      -2 147 483 648 ... 2 147 483 647
    cout << "long long:\t\t"        << sizeof(long long)        << " bytes" << endl;        // 8 bytes      -9 223 372 036 854 775 808 ... 9 223 372 036 854 775 807
    cout << "float:\t\t\t"          << sizeof(float)            << " bytes" << endl;        // 4 bytes      1,175494351 E–38 ... 3,402823466 E+38
                                                                                            //              -2 147 483 648.0 ... 2 147 483 647.0
    cout << "double:\t\t\t"         << sizeof(double)           << " bytes" << endl;        // 8 bytes      2,2250738585072014 E–308 ... 1,7976931348623158 E+308
                                                                                            //              -9 223 372 036 854 775 808.0 ... 9 223 372 036 854 775 807.0
    cout << "long double:\t\t"      << sizeof(long double)      << " bytes" << "\n\n\n\n";  // 8 bytes



    cout << "base_unit:\t\t"        << sizeof(base_unit)        << " bytes" << endl;        // D:96  / R:72  bytes
    cout << "element<bool>:\t\t"    << sizeof(element<bool>)    << " bytes" << endl;        // D:104 / R:80  bytes
    cout << "collect<bool>:\t\t"    << sizeof(collect<bool>)    << " bytes" << "\n\n";      // D:48  / R:32  bytes

    cout << "filter<bool>:\t\t"     << sizeof(filter<bool>)     << " bytes" << endl;        // D:16  / R:16  bytes
    cout << "filter<storage>:\t"    << sizeof(filter<storage>)  << " bytes" << endl;        // D:592 / R:464 bytes
    cout << "filter<product>:\t"    << sizeof(filter<product>)  << " bytes" << "\n\n";      // D:944 / R:720 bytes

    cout << "state:\t\t\t"          << sizeof(state)            << " bytes" << endl;        // D:16  / R:16  bytes
    cout << "settings:\t\t"         << sizeof(settings)         << " bytes" << endl;        // D:1   / R:1   bytes
    cout << "access:\t\t\t"         << sizeof(access)           << " bytes" << "\n\n";      // D:96  / R:72  bytes

    cout << "cuboid_size:\t\t"      << sizeof(cuboid_size)      << " bytes" << endl;        // D:104 / R:80  bytes
    cout << "box_size:\t\t"         << sizeof(box_size)         << " bytes" << endl;        // D:104 / R:80  bytes
    cout << "storage_type:\t\t"     << sizeof(storage_type)     << " bytes" << endl;        // D:112 / R:88  bytes
    cout << "storage:\t\t"          << sizeof(storage)          << " bytes" << "\n\n";      // D:144 / R:112 bytes

    cout << "union_val:\t\t"        << sizeof(union_val)        << " bytes" << endl;        // D:8-32/ R:8-32bytes
    cout << "property_type:\t\t"    << sizeof(property_type)    << " bytes" << endl;        // D:224 / R:176 bytes
    cout << "Property:\t\t"         << sizeof(Property)         << " bytes" << "\n\n";      // D:136 / R:104 bytes

    cout << "product_type:\t\t"     << sizeof(product_type)     << " bytes" << endl;        // D:128 / R:96  bytes
    cout << "product:\t\t"          << sizeof(product)          << " bytes" << endl;        // D:232 / R:176 bytes
    cout << "product_part:\t\t"     << sizeof(product_part)     << " bytes" << "\n\n";      // D:136 / R:112 bytes


    cout << "user:\t\t\t"           << sizeof(user)             << " bytes" << endl;        // D:2   / R:2   bytes
}