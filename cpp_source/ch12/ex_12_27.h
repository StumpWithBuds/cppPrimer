#ifndef EX12_27_H
#define EX12_27_H

#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>

class QueryResult; //为了定义函数query的返回类型，这个定义是必须的

class TextQuery
{
public:
    // 行号的类型
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string& s) const;

private:
	std::shared_ptr<std::vector<std::string> > file; // 输入文件
    // 每个单词到它所在的行号的集合的映射
	std::map<std::string, std::shared_ptr<std::set<line_no> > > wm;
};

TextQuery::TextQuery(std::ifstream& ifs): file(new std::vector<std::string>) 
{
	std::string text;
	while (getline(ifs, text))
	{
		file->push_back(text);  // 保存文本
		int n = file->size() - 1;  // 当前行号
		std::istringstream line(text);
		std::string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new std::set<line_no>);  // 如果第一次遇到这个单词，则新建一个set
			lines->insert(n);
		}
	}
}

class QueryResult
{
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);
	QueryResult(std::string s,
				std::shared_ptr<std::set<TextQuery::line_no> > p,
				std::shared_ptr<std::vector<std::string> > f) :
		sought(s), lines(p), file(f) 
	{}

private:
	std::string sought;  // 查询的单词
	std::shared_ptr<std::set<TextQuery::line_no> > lines;  // 出现的行号
	std::shared_ptr<std::vector<std::string> > file;  // 输入文件
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif