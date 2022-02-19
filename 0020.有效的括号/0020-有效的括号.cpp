class Solution {
public:
    bool isValid(string s) {
        deque<char> m_queue;
        for(char c: s)
        {
            if(c == '(') m_queue.push_back(')');
            else if(c == '{') m_queue.push_back('}');
            else if(c == '[') m_queue.push_back(']');
            else if(c == ')')
            {
                if(!m_queue.empty() && m_queue.back() == ')') m_queue.pop_back();
                else return false;
            }
            else if(c == '}')
            {
                if(!m_queue.empty() && m_queue.back() == '}') m_queue.pop_back();
                else return false;
            }
            else if(c == ']')
            {
                if(!m_queue.empty() && m_queue.back() == ']') m_queue.pop_back();
                else return false;
            }
        }
        if(m_queue.empty()) return true;
        else return false;
    }
};