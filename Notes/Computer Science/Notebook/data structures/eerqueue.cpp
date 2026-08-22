#include <bits/stdc++.h>

using namespace std;

template<int alpha>
class EerQueue
{
	static_assert(alpha > 0);
public:
	struct Node
	{
		std::array<Node*, alpha> next;
		Node* pre, * fail;
		int len;
		int rightmost_occurence, second_rightmost_occurence;
		// The (second) rightmost occurence of the palindrome associated with this Node.
		int fail_cnt;
		// The count of fails that link to this Node.
		Node() : pre(nullptr), fail(nullptr), len(0), next{}, rightmost_occurence(-1), second_rightmost_occurence(-1), fail_cnt(0) { }
		void UpdateOccurence(int occurence)
		{
			if (occurence > rightmost_occurence)
			{
				second_rightmost_occurence = rightmost_occurence;
				rightmost_occurence = occurence;
			}
			else if (occurence > second_rightmost_occurence)
				second_rightmost_occurence = occurence;
		}
	};
private:
	int node_cnt;
	Node* odd_root, * even_root, * cur;
	// cur is the Node of the longest suffix palindrome.
	Node* NewNode(int len = 0)
	{
		Node* it = new Node();
		it->len = len;
		return it;
	}
	int start;
	std::vector<int> data;
	std::vector<Node*> prefix_palindrome;
	int size;
	Node* GetFail(Node* it, int pos)
	{
		while (pos - it->len - 1 < start || data[pos - it->len - 1] != data[pos])
			it = it->fail;
		return it;
	}
public:
	EerQueue() : node_cnt(0), start(0), size(0)
	{
		odd_root = NewNode(-1);
		even_root = NewNode(0);
		odd_root->fail = odd_root; odd_root->fail_cnt += 1;
		even_root->fail = odd_root; odd_root->fail_cnt += 1;
		cur = even_root;
	}
	Node* Push(int x)
	{
		assert(0 <= x && x < alpha);
		int pos = data.size();
		data.push_back(x);
		prefix_palindrome.push_back(nullptr);
		Node* it = GetFail(cur, pos);
		if (it->next[x] == nullptr)
		{
			Node* tmp = NewNode(it->len + 2);
			tmp->pre = it;
			tmp->fail = GetFail(it->fail, pos)->next[x];
			if (tmp->fail == nullptr) tmp->fail = even_root;
			tmp->fail->fail_cnt += 1;
			it->next[x] = tmp;
			size += 1;
		}
		cur = it->next[x];
		int occurence = pos - cur->len + 1;
		cur->UpdateOccurence(occurence);
		prefix_palindrome[occurence] = cur;
		return cur;
	}
	void Pop()
	{
		assert(start < (int)data.size());
		Node* longest_prefix_palindrome = prefix_palindrome[start];
		if (longest_prefix_palindrome->len == (int)data.size() - start)
			cur = cur->fail;
		Node* it = longest_prefix_palindrome->fail;
		if (start != (int)data.size() - 1)
		{
			int occurence = start + longest_prefix_palindrome->len - it->len;
			it->UpdateOccurence(occurence);
			if (prefix_palindrome[occurence] == nullptr || it->len > prefix_palindrome[occurence]->len)
				prefix_palindrome[occurence] = it;
		}
		if (longest_prefix_palindrome->fail_cnt == 0 && longest_prefix_palindrome->second_rightmost_occurence < start)
		{
			int x = data[start];
			longest_prefix_palindrome->pre->next[x] = nullptr;
			it->fail_cnt -= 1;
			size -= 1;
		}
		start += 1;
	}
	int NumOfPalindromes()
	{
		return size;
	}
};


void solve()
{
	int q;
	cin >> q;
	constexpr int alpha = 26;
	EerQueue<alpha> g;
	while (q--)
	{
		string op;
		cin >> op;
		if (op == "push")
		{
			char c;
			cin >> c;
			g.Push(c - 'a');
		}
		else
			g.Pop();
		cout << g.NumOfPalindromes() << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}