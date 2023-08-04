/*/////////////////////////////////////////////////////////////////////////
Workshop - #6 (P1)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include <cstring>
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strlen(lineValue) + 1];
      strcpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }

   void TextFile::setEmpty() {
      if (m_textLines != nullptr) {
         delete[] m_textLines;
         m_textLines = nullptr;
      }
      if (m_filename != nullptr) {
         delete[] m_filename;
         m_filename = nullptr;
      }
      m_noOfLines = 0;
   }
   void TextFile::setFilename(const char* fname, bool isCopy) {
      if (isCopy == false) {
         delete[] m_filename;
         m_filename = new char[strlen(fname)+ 1];
         strcpy(m_filename, fname);
      }
      else {
         char prefix[100] = { "C_" };
         strcat(prefix, fname);
         m_filename = new char[strlen(prefix) + 1];
         strcpy(m_filename, prefix);
      }
   }
   void TextFile::setNoOfLines() {
      ifstream txtFile;
      txtFile.open(m_filename);
      char ch;
      while (txtFile.get(ch)) {
         if (ch == '\n') {
            m_noOfLines++;
         }
      }
      if (m_noOfLines == 0) {
         delete[] m_filename;
         m_filename = nullptr;
      }
      m_noOfLines++;
      txtFile.close();
   }
   void TextFile::loadText() {
      if (m_filename != nullptr) {
         delete[] m_textLines;
         m_textLines = new Line[m_noOfLines];
         ifstream txtFile;               // local instance of ifstream with name m_filename
         txtFile.open(m_filename);
         string line;                    // local string
         int i = 0;
         if (txtFile.is_open()) {
            while (getline(txtFile, line)) {   // read line using local string and getline f'n
               m_textLines[i] = line.c_str();  // read each line into string set m_textLines array in a loop  
               i++;
            }
            m_noOfLines = i;                   // update values of m_noOfLines to actual number of lines read
         }
         txtFile.close();
      }
      
   }
   void TextFile::saveAs(const char* fileName)const {
      ofstream newFile(fileName);
     
      if (newFile.is_open()) {
         for (unsigned i = 0; i < m_noOfLines; i++) {
            newFile << m_textLines[i] << '\n';
         }
      }
      newFile.close();
   }

   TextFile::TextFile(unsigned pageSize) {
      m_textLines = nullptr;
      m_filename = nullptr;
      m_noOfLines = 0;
      m_pageSize = pageSize;
   }
   TextFile::TextFile(const char* filename, unsigned pageSize) {
      m_textLines = nullptr;
      m_filename = nullptr;
      m_noOfLines = 0;
      m_pageSize = pageSize;
      if (filename && filename != nullptr) {
         m_filename = new char[strlen(filename)+ 1];
         setFilename(filename);
         setNoOfLines();
         loadText();
      }
   }
   TextFile::TextFile(const TextFile& txtFile) {
      m_filename = nullptr;
      m_textLines = nullptr;
      m_noOfLines = 0;                                            //set all other attributes to nullptr & 0
      this->m_pageSize = txtFile.m_pageSize;                      //initalize m_pageSize to incoming m_pageSize value
      if (txtFile.m_filename != nullptr) {                        //if incoming text object is valid (has a filename)
         m_filename = new char[strlen(txtFile.m_filename) + 1];
         strcpy(m_filename, txtFile.m_filename);
         setNoOfLines();                                          //set number of lines 
         loadText();                                              //load text into the m_textLines array
         delete[] m_filename;
         setFilename(txtFile.m_filename, true);                         //Set filename to the name of incoming TextFile object
         saveAs(m_filename);                                      //saves the content of the incoming TextFile under filename of current TextFile
      }
   }
   TextFile& TextFile::operator=(const TextFile& txtFile) {
      if (this->m_filename != nullptr && txtFile.m_filename != nullptr) {  // check if current & incoming TextFiles are valid
         m_noOfLines = txtFile.m_noOfLines;              //copy incoming m_noOfLines to current obj
         string tempFN;                                 
         tempFN = m_filename;
         setFilename(txtFile.m_filename, false);
         loadText();
         strcpy(m_filename,tempFN.c_str());
         saveAs(m_filename);
      }
      return *this;
   }
   TextFile::~TextFile() {
      if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
      }
      if (m_filename != nullptr) {
         delete[] m_filename;
         m_filename = nullptr;
      }
   }

   std::ostream& TextFile::view(std::ostream& ostr)const {
      if (m_filename != nullptr && m_textLines != nullptr) {
         ostr << m_filename << endl;
         for (unsigned i = 0; i < strlen(m_filename); i++) {
            ostr << '=';
         }
         ostr << '\n';
         unsigned j;
         for (unsigned i = 0; i < m_noOfLines; i += m_pageSize) {
            for (j = i; j < i + m_pageSize && j < m_noOfLines; j++) {
               ostr << m_textLines[j] << endl;
               if (m_noOfLines < m_pageSize && j == m_noOfLines) { break; }
            }
            if (j % m_pageSize == 0) {
               ostr << "Hit ENTER to continue..." << endl;
               //while (cin.get() != '\n');
            }
         }
      }
      return ostr;
   }
   std::istream& TextFile::getFile(std::istream& istr) {
      string line;
      istr >> line; 
      setFilename(line.c_str());
      setNoOfLines();
      loadText();
      return istr;
   }

   TextFile::operator bool()const {
      bool ret = false;
      if (m_noOfLines != 0 && m_textLines != nullptr && m_filename != nullptr) { ret = true; }
      return ret;
   }
   unsigned TextFile::lines()const { return m_noOfLines; }
   const char* TextFile::name()const { return m_filename; }

   const char* TextFile::operator[](unsigned index)const {
      unsigned numLines = m_noOfLines;

      if (index >= numLines) {
         index %= numLines;  
      }
      return &(m_textLines[index][0]);
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
      text.view(ostr);
      return ostr;
   }
   std::istream& operator>>(std::istream& istr, TextFile& text) {
      text.getFile(istr);
      return istr;
   }
}