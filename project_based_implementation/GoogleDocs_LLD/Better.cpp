#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

// Abstraction for document elements
class DocumentElement {
public:
    virtual string render() = 0;
};

// Concrete implementation for text elements
class TextElement : public DocumentElement {
private:
    string text;

public:
    TextElement(string text) {
        this->text = text;
    }

    string render() override {
        return text;
    }
};

// Concrete implementation for image elements
class ImageElement : public DocumentElement {
private:
    string imagePath;

public:
    ImageElement(string imagePath) {
        this->imagePath = imagePath;
    }

    string render() override {
        return "[Image: " + imagePath + "]";
    }
};

// NewLineElement represents a line break in the document.
class NewLineElement : public DocumentElement {
public:
    string render() override {
        return "\n";
    }
};

// TabSpaceElement represents a tab space in the document.
class TabSpaceElement : public DocumentElement {
public:
    string render() override {
        return "\t";
    }
};

// Document class responsible for holding a collection of elements
class Document {
private:
    vector<DocumentElement*> documentElements;

public:
    void addElement(DocumentElement* element) {
        documentElements.push_back(element);
    }

    // Renders the document by concatenating the render output of all elements.
    string render() {
        string result;
        for (auto element : documentElements) {
            result += element->render();
        }
        return result;
    }
};

// Persistence abstraction
class Persistence {
public:
    virtual void save(string data) = 0;
};

// FileStorage implementation of Persistence
class FileStorage : public Persistence {
public:
    void save(string data) override {
        ofstream outFile("document.txt");
        if (outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

// Placeholder DBStorage implementation
class DBStorage : public Persistence {
public:
    void save(string data) override {
        // db save logic
    }
};

class DocumentEditor {
private:
    Document* document;
    Persistence* storage;
    string renderedDocument;

public:
    DocumentEditor(Document* document, Persistence* storage) {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text) {
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath) {
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine() {
        document->addElement(new NewLineElement());
    }

    void addTabSpace() {
        document->addElement(new TabSpaceElement());
    }

    string renderDocument() {
        if(renderedDocument.empty()) {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument() {
        storage->save(renderDocument());
    }
};

int main() {
    Document* document = new Document();
    Persistence* persistence = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document, persistence);
    
    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    cout << editor->renderDocument() << endl;

    editor->saveDocument();

    return 0;
}