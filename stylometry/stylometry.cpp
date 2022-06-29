#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
#include<sstream>
#include<numeric>
#include<cmath>

using std::cout;    using std::endl;
using std::ifstream;    using std::string;
using std::vector;

const vector<string> FEATURE_VEC{
    "a", "about", "above", "after", "again", "against", "all",
    "am", "an", "and", "any", "are", "aren't", "as", "at", "be",
    "because", "been", "before", "being", "below", "between", "both",
    "but", "by", "can't", "cannot", "could", "couldn't", "did", "didn't",
    "do", "does", "doesn't", "doing", "don't", "down", "during", "each",
    "few", "for", "from", "further", "had", "hadn't", "has", "hasn't",
    "have", "haven't", "having", "he", "he'd", "he'll", "he's", "her",
    "here", "here's", "hers", "herself", "him", "himself", "his", "how",
    "how's", "i", "i'd", "i'll", "i'm", "i've", "if", "in", "into", "is",
    "isn't", "it", "it's", "its", "itself", "let's", "me", "more", "most",
    "mustn't", "my", "myself", "no", "nor", "not", "of", "off", "on", "once",
    "only", "or", "other", "ought", "our", "ours", "ourselves", "out", "over",
    "own", "same", "shan't", "she", "she'd", "she'll", "she's", "should", "shouldn't",
    "so", "some", "such", "than", "that", "that's", "the", "their", "theirs", "them",
    "themselves", "then", "there", "there's", "these", "they", "they'd", "they'll", "they're",
    "they've", "this", "those", "through", "to", "too", "under", "until", "up", "very", "was",
    "wasn't", "we", "we'd", "we'll", "we're", "we've", "were", "weren't", "what", "what's", "when",
    "when's", "where", "where's", "which", "while", "who", "who's", "whom", "why", "why's", "with",
    "won't", "would", "wouldn't", "you", "you'd", "you'll", "you're", "you've", "your", "yours",
    "yourself", "yourselves", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".",
    "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_", "`", "{", "|", "}", "~"
};
// 此处必须用引用传递的方式，原因就是fstream 对象没有复制构造函数.
// 因此不能执行复制操作，而函数是实参复制给形参，因此这里就出错。
// 因此，我们必须使用引用的方式传递参数。
string fileToString(ifstream& file);
double dotProduct(const vector<int>& vec1, const vector<int>& vec2);
double mag(const vector<int>& vec);
int countOccurences(string word, string text);
vector<int> createFreqVec(const string& text) ;
double getSimilarity(const string& text1, const string& text2); 

int main(int argc, char *argv[]) {
    // 使用文件stream读取txt文件
    ifstream file1("madison.txt");
    ifstream file2("jj.txt");
    ifstream file3("hamilton.txt");
    ifstream file4("unknown.txt");

    string f_mad = fileToString(file1);
    string f_jj = fileToString(file2);
    string f_ham = fileToString(file3);
    string f_unk = fileToString(file4);

    cout << "Similarity madison - unknown " << getSimilarity(f_mad, f_unk) << endl;
    cout << "Similarity jj - unknown " << getSimilarity(f_jj, f_unk) << endl;
    cout << "Similarity hamilton - unknown " << getSimilarity(f_ham, f_unk) << endl;

    return 0;
}

string fileToString(ifstream& file) {
    string ret = "";
    string line;

    while(std::getline(file, line)) {
        // 此处可以用transform代替for循环
        // 或者直接使用back_inserter直接写入到ret里面
        std::transform(line.begin(), line.end(), line.begin(), tolower);
        ret += line + " ";
        // for(char c : line) {
        //     c = tolower(c);
        //     ret += c;
        // }     
    }
    return ret;
}

double getSimilarity(const string& text1, const string& text2) {
    // 先统计频率
    vector<int> freqVec1 = createFreqVec(text1);
    vector<int> freqVec2 = createFreqVec(text2);

    // 再计算点积
    int dotProd = dotProduct(freqVec1, freqVec2);

    // 然后计算余弦相似度
    return dotProd / (mag(freqVec1), mag(freqVec2));
}

vector<int> createFreqVec(const string& text) {
    vector<int> result;
    for(auto & word : FEATURE_VEC) {
        result.push_back(countOccurences(word, text));
    }
    return result;
}

// 数出该字符在文档中出现的频率
int countOccurences(string word, string text) {
    int i = 0;
    // 通过两端加空格的方式进行搜索，但这种方法也无法找到后面跟标点情况下的单词。
    string toFind = " " + word + " ";
    auto curr = text.begin();
    auto end = text.end();

    // while(curr != end) {
    // // 此处不能使用count函数，而必须使用search函数，因为count只能比较普通的类型
    // // 而此时我们要比较的是字符串，在C++内部编译的时候会自动转换为指针。
    //     auto found = std::search(curr, end, toFind.begin(), toFind.end());
    //     if(found == end)
    //         break;
    //     i++;
    //     curr = found + 1;
    // } 
    // 将字符串类型按照空格分开。但这样的话可以忽略空格的影响但是不能对标点符号计数
    std::stringstream input(text);
    string result;
    while(input >> result) {
        if (word == result)
            i++;
    }

    return i;
}

double dotProduct(const vector<int>& vec1, const vector<int>& vec2) {
    return std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
}

double mag(const vector<int>& vec) {
    return std::sqrt(dotProduct(vec, vec));
}