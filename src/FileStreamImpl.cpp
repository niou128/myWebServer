#include "../headers/FileStreamImpl.h"

// CONSTRUCTOR / DESTRUCTOR
//////////////////////////////////////////////////////////
FileStreamImpl::FileStreamImpl()
{
  this->currentLineContent = "";
}

FileStreamImpl::~FileStreamImpl()
{
  this->close();
}

// PUBLIC METHODS
//////////////////////////////////////////////////////////
bool FileStreamImpl::close()
{
  if (this->fileInput.is_open() && this->fileOutput.is_open())
  {
    this->fileInput.close();
    this->fileOutput.close();
    return true;
  }
  return false;
}

bool FileStreamImpl::open(string& filePath)
{
  this->fileOutput.open(filePath.c_str(), ios_base::out | ios_base::app);
  if (this->fileOutput.is_open())
  {
    this->fileInput.open(filePath.c_str(), ios_base::in);
    if (this->fileInput.is_open())
    {
      return true;
    }
  }
  return false;
}

string& FileStreamImpl::read()
{
  getline(this->fileInput, this->currentLineContent);
  return this->currentLineContent;
}

int FileStreamImpl::write(string& line)
{
  int lineLength;
  int writtenCharactersCount;
  int currentLine;
  writtenCharactersCount = 0;
  if (this->fileOutput.is_open())
  {
    lineLength = line.length();
    currentLine = this->fileInput.tellg();
    this->fileOutput.write(line.c_str(), lineLength);
    if (this->fileOutput.good())
    {
      writtenCharactersCount = lineLength;
      this->fileOutput.seekp(currentLine);
    }
  }
  return writtenCharactersCount;
}