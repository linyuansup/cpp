#ifndef UNTITLED__HUFFMAN_TREE_H
#define UNTITLED__HUFFMAN_TREE_H

using namespace std;

class HuffmanTree
{
private:
	struct node
	{
		node* smallChild{}, * bigChild{};
		int freq{};
		char data{};
		explicit node(char data, int freq)
		{
			this->data = data;
			this->freq = freq;
		}
		node() = default;
	};
	node* root = nullptr;
	bool isValueNode(node* pos);
	void ZipRelation(map<char, string>& data, node* pos, string nowString);
public:
	void insertData(int* freq);
	map<char, string> getZipRelation();
	char findCorrChar(string& s);
};

void HuffmanTree::insertData(int* freq)
{
	// add freq information
	list < node * > nodeData(256);
	auto pos = nodeData.begin();
	for (int i = 0; i < 256; i++, pos++)
		*pos = new node(static_cast<char>(i - 128), freq[i]);

	// delete not used node
	for (auto deletePos = nodeData.begin(); deletePos != nodeData.end(); deletePos++)
		if ((*deletePos)->freq == 0)
			nodeData.erase(deletePos--);

	// sort
	nodeData.sort([](const node* s1, const node* s2)
	{
	  return s1->freq < s2->freq;
	});

	// make tree
	while (nodeData.size() != 1)
	{
		// make node a link
		node* here = new node;
		here->smallChild = nodeData.front();
		nodeData.pop_front();
		here->bigChild = nodeData.front();
		nodeData.pop_front();
		here->freq = here->bigChild->freq + here->smallChild->freq;

		// add "here" to nodeData with order
		bool added = false;
		for (auto insertPos = nodeData.begin(); insertPos != nodeData.end(); insertPos++)
			if ((*insertPos)->freq >= here->freq)
			{
				nodeData.insert(insertPos, here);
				added = true;
				break;
			}

		// if not added, it must the max one
		if (!added)
			nodeData.insert(nodeData.end(), here);
	}
	root = nodeData.front();
	nodeData.clear();
}

map<char, string> HuffmanTree::getZipRelation()
{
	map<char, string> returnData;
	ZipRelation(returnData, root->smallChild, "0");
	ZipRelation(returnData, root->bigChild, "1");
	return returnData;
}

bool HuffmanTree::isValueNode(node* pos)
{
	return !pos->smallChild;
}

void HuffmanTree::ZipRelation(map<char, string>& data, HuffmanTree::node* pos, string nowString)
{
	if (pos)
	{
		if (isValueNode(pos))
			data.insert(pair<char, string>(pos->data, nowString));
		else
		{
			ZipRelation(data, pos->smallChild, nowString + "0");
			ZipRelation(data, pos->bigChild, nowString + "1");
		}
	}
}

char HuffmanTree::findCorrChar(string& s)
{
	node* pos = root;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
			pos = pos->smallChild;
		else
			pos = pos->bigChild;
		if (isValueNode(pos))
		{
			s = s.substr(i + 1);
			return pos->data;
		}
	}
	return -1;
}

#endif //UNTITLED__HUFFMAN_TREE_H
