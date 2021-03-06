////////////////////////////////////////////////////
// This file is part of NoLifeStory.              //
// Please see SuperGlobal.h for more information. //
////////////////////////////////////////////////////

namespace NLS {
	class Node {
	public:
		Node();
		Node(const Node&);
		Node& operator= (const Node&);
		Node operator[] (const string&) const;
		Node operator[] (const char[]) const;
		Node operator[] (const int&) const;
		Node operator[] (const Node&) const;
		Node g(const string&);
		map<string, Node>::const_iterator begin() const;
		map<string, Node>::const_iterator end() const;
		map<string, Node>::const_reverse_iterator rbegin() const;
		map<string, Node>::const_reverse_iterator rend() const;
		string Name() const;
		void InitTop(const string&);
		void Assign(const Node&);
		operator bool() const;
		operator string() const;
		operator double() const;
		operator int() const;
		operator Sprite() const;
		operator Sound() const;
		void Set(const string&);
		void Set(const double&);
		void Set(const int&);
		void Set(class Img*);
		void Set(const class Sound&);
		void Set(const class Sprite&);
	private:
		Node(const Node&, const string&);
		class NodeData* data;
	};
	class PNGProperty {
	public:
		PNGProperty(ifstream* file, Node n);
		void Parse();
	private:
		ifstream* file;
		Sprite sprite;
		int32_t format;
		int32_t length;
		uint32_t offset;
		uint8_t format2;
	};
	class SoundProperty {
	public:
		SoundProperty(ifstream* file, Node n);
		uint32_t GetStream(bool loop);
	private:
		int32_t len;
		uint8_t* data;
		uint32_t offset;
		ifstream* file;
	};
	class Img {
	public:
		Img(ifstream* file, Node n, uint32_t offset);
		void Parse();
	private:
		Node n;
		uint32_t offset;
		ifstream* file;
	};
	extern Node WZ;
	extern uint16_t Version;
	extern vector<path> Paths;
	void InitWZ();
}
