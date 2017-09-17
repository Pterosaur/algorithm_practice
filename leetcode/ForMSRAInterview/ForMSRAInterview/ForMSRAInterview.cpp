// ForMSRAInterview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

using Stream = char *;

struct StringStream {
    Stream m_stream;
    int    m_total_length;
    int    m_current_position;
    int Read_Data(char * buffer, int length) {
        return length;
    }
    int Write_Data(char * buffer, int length) {
        return 0;
    }
};

struct Raw_Text{
    StringStream m_raw_stream;
    int Input(char * buffer, int length) {
        return m_raw_stream.Read_Data(buffer, length);
    }
};

struct Format_Data {
};

struct Section_Data {
    const char *       m_sec_name;
    const char *       m_position;
    const unsigned int m_id;
    set<Section_Data>  m_sub_section;
};

struct Content_Data {
    const char * m_content;
};

struct Format_Text {
    virtual bool Add_Data(Raw_Text & rt) = NULL;
    virtual bool Output(StringStream & sd) const = NULL;
};

struct GZ_Text : Format_Text{
public:
    bool Add_Data(Raw_Text & rt) {
        return true;
    }
    bool Output(StringStream & sd) const{
        //...
        return true;
    }
    GZ_Text() {}
private:
    bool Add_Secontion(Section_Data & sd) {
        return true;
    }
    bool Add_Content(Content_Data & cd) {
        return true;
    }
    Section_Data  m_root_section;
    Content_Data  m_content;
};


struct Filter {
    virtual bool do_filter(const Raw_Text & rt, Format_Text & ft) = NULL;
};

struct Filter_Garbage : Filter{
    bool do_filter(const Raw_Text & rt, Format_Text & ft) {
        return true;
    }
};

struct Filter_Format : Filter {
    bool do_filter(const Raw_Text & rt, Format_Text & ft) {
        return true;
    }

};

struct Filter_Section {
    bool do_filter(const Raw_Text & rt, Format_Text & ft) {
        return true;
    }

};



bool Convert(Raw_Text & rt, GZ_Text & gt, vector<Filter*> & filters) {
    for (auto f : filters) {
        if ( ! f->do_filter(rt, gt)) {
            return false;
        }
    }
    return true;
}






int main()
{
    StringStream Download;
    StringStream Print;

    vector<Filter *> filter;
    Raw_Text rt(Dowload);
    GZ_Text gt(Print);


    //initialize filter
    filter.push_back(new Filter_Format());
    filter.push_back(new Filter_Garbage());
    filter.push_back(new Filter_Section());


    Convert(rt, gt, filter);


    return 0;
}

