#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class DocumentElement
{
public:
  virtual string render() = 0;
};

class TextElement : public DocumentElement
{
private:
  string text;

public:
  TextElement(string t)
  {
    this->text = t;
  }
  string render() override
  {
    return text;
  }
};

class ImageElement : public DocumentElement
{
private:
  string imagePath;

public:
  ImageElement(string path)
  {
    this->imagePath = path;
  }

  string render() override
  {
    return "<img src=\"" + imagePath + "\" />";
  }
};

class NewLineElement : public DocumentElement
{
public:
  string render() override
  {
    return "\n";
  }
};

class TabSpaceElement : public DocumentElement
{
public:
  string render() override
  {
    return "\t";
  }
};

class Document
{
private:
  vector<DocumentElement *> elements;

public:
  void addElement(DocumentElement *element)
  {
    elements.push_back(element);
  }

  string render()
  {
    string result;
    for (auto element : elements)
    {
      result += element->render();
    }
    return result;
  }
};

class Persistence
{
public:
  virtual void save(string data) = 0;
};

class FileStorage : public Persistence
{
public:
  void save(string data) override
  {
    ofstream outFile("document.txt");
    if (outFile)
    {
      outFile << data;
      outFile.close();
      cout << "Document saved to document.txt" << endl;
    }
    else
    {
      cout << "Error: Unable to open file for writing." << endl;
    }
  }
};

// Placeholder DBStorage implementation
class DBStorage : public Persistence
{
public:
  void save(string data) override
  {
    // Save to DB
  }
};

class DocumentEditor
{
private:
  Document *doc;
  Persistence *persistence;
  string renderedDocument;

public:
  DocumentEditor(Document *doc, Persistence *per)
  {
    this->doc = doc;
    this->persistence = per;
  }

  void addText(string text)
  {
    doc->addElement(new TextElement(text));
  }

  void addImage(string imagePath)
  {
    doc->addElement(new ImageElement(imagePath));
  }

  void addNewLine()
  {
    doc->addElement(new NewLineElement());
  }

  void addTabSpace()
  {
    doc->addElement(new TabSpaceElement());
  }

  string renderDocument()
  {
    renderedDocument = doc->render();
    return renderedDocument;
  }

  void saveDocument()
  {
    if (renderedDocument.empty())
    {
      cout << "Error: Document is empty. Nothing to save." << endl;
      return;
    }
    persistence->save(renderedDocument);
  }
};

int main()
{
  Document *doc = new Document();
  Persistence *persistence = new FileStorage();
  DocumentEditor *editor = new DocumentEditor(doc, persistence);
  editor->addText("Hello, World!");
  editor->addNewLine();
  editor->addText("This is a test document.");
  editor->addNewLine();
  editor->addImage("image.png");
  editor->addTabSpace();
  editor->addText("End of document.");
  string rendered = editor->renderDocument();
  cout << "Rendered Document:\n"
       << rendered << endl;
  editor->saveDocument();
  delete editor;
  delete persistence;
  delete doc;
  return 0;
}