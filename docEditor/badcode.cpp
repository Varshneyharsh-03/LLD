#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class DocumentEditor
{
private:
  vector<string> docElements;
  string renderedDoc;

public:
  void addImage(string path)
  {
    docElements.push_back(path);
  }
  void addText(string txt)
  {
    docElements.push_back(txt);
  }
  string renderDoc()
  {
    if (renderedDoc.empty())
    {
      string result;
      for (auto element : docElements)
      {
        if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
                                   element.substr(element.size() - 4) == ".png"))
        {
          result += "[Image: " + element + "]" + "\n";
        }
        else
        {
          result += element + "\n";
        }
      }
      renderedDoc = result;
    }
    return renderedDoc;
  }

  void saveToFile()
  {
    ofstream file("document.txt");
    if (file.is_open())
    {
      file << renderDoc();
      file.close();
      cout << "Document saved to document.txt" << endl;
    }
    else
    {
      cout << "Error: Unable to open file for writing." << endl;
    }
  }
};

int main()
{
  DocumentEditor *editor = new DocumentEditor();
  editor->addText("This is a sample document.");
  editor->addImage("image1.jpg");
  editor->addText("This document contains an image.");
  editor->addImage("image2.png");
  editor->addText("End of the document.");
  cout << editor->renderDoc() << endl;
  editor->saveToFile();
  delete editor;    // Free the allocated memory
  editor = nullptr; // Avoid dangling pointer
  cout << "Document editing completed." << endl;
  return 0;
}