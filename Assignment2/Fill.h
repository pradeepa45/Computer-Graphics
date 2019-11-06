#define ID_DRAW_POLY       40001
#define ID_CLEAR           40002
#define ID_EXIT            40003
#define ID_FILL            40004

const COLORREF CLR_BG = RGB(255, 255, 255);
const COLORREF CLR_BOUNDARY = RGB(0, 0, 0);
const COLORREF CLR_DEFAULT = RGB(0, 255, 255);
const COLORREF CLR_XY = RGB(0, 0, 255);
const COLORREF CLR_YZ = RGB(0, 255, 0);
const COLORREF CLR_XZ = RGB(255, 255, 0);
const COLORREF CLR_XYZ = RGB(255, 0, 0);
const int MODE_CLEAR = 0;
const int MODE_X = 1;
const int MODE_Y = 2;
const int MODE_Z = 4;
const int MODE_XY = MODE_X ^ MODE_Y;
const int MODE_XZ = MODE_X ^ MODE_Z;
const int MODE_YZ = MODE_Y ^ MODE_Z;
const int MODE_XYZ = MODE_X ^ MODE_Y ^ MODE_Z;


typedef enum
{
  READY_MODE,
  DRAW_MODE,
  DRAWN_MODE,
  FILL_MODE,
  FILLED_MODE
} MODE;

const int nMaxNoOfCornerPts = 9;

typedef struct
{
  HDC hdcMem; 
  HBITMAP hbmp;
  HPEN hDrawPen, hFillPen[8];
  MODE drawMode;
  POINT cornerPts[3][3];/* corner points of the 3 triangles */
  SIZE maxBoundary;
  int nCornerPts; /* total number of corner points */ 
} DRAWING_DATA;

typedef struct
{
  int yMin, yMax;
  double x;
  double mInv;
  int type;
} EDGE_ENTRY;

extern DRAWING_DATA gDrawData; // global data being shared across files

void setupMenus(HWND hwnd);
void processPolygon(HWND hwnd);
void processCommand(int cmd, HWND hwnd);
void setDrawMode(MODE mode, HWND hwnd);
void reDraw(HWND hwnd);
void processCommonCommand(int cmd, HWND hwnd);