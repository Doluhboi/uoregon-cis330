// This program is from: 
// The author believes it has <X> memory errors
class Rectangle{
private:
  int height, width;

public: 
  void Halve(Rectangle r);
  void Double(Rectangle r);
  int Area(Rectangle r);
  int getWidth();
  int getHeight();
  void setDimensions(int h, int w);
};
void 
Rectangle::setDimensions(int h, int w){
  height = h;
  width = w;
}

void
Rectangle::Halve(Rectangle r){
  height =(r.height)/2;
  width = (r.width)/2;
}
void 
Rectangle::Double(Rectangle r){
  height = (r.height)*2;
  width = (r.width)*2;

}
int
Rectangle::getWidth(){
  return width;
}
int
Rectangle::getHeight(){
  return height;
}

int
Rectangle::Area(Rectangle r){
  return r.height*r.width;
}

int main()
{ 
  int w;
  int h;
  h = 6;
  w = 4;
  Rectangle rect;
  rect.setDimensions(h,w);
  rect.Halve(rect);
  rect.Double(rect);
  rect.Double(rect);
  rect.Area(rect);
}
