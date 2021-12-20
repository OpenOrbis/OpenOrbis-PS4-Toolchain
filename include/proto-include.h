#include <freetype/ftglyph.h>
#include <freetype/ftstroke.h>
#include <ft2build.h>
#include <freetype/ftlcdfil.h>

#include <stdint.h>

#ifndef _SCE_FREETYPE_H_
#define _SCE_FREETYPE_H_

#ifdef __cplusplus 
extern "C" {
#endif

/*------------ END FREE TYPE -----------------------*/


typedef struct FT_LibraryRec_* FT_Library;
typedef struct FT_FaceRec_* FT_Face;
typedef unsigned char  FT_Byte;

#define FT_OPEN_MEMORY 0x1 
#define FT_OPEN_STREAM 0x2

#define ft_memchr   memchr
#define ft_memcmp   memcmp
#define ft_memcpy   memcpy
#define ft_memmove  memmove
#define ft_memset   memset
#define ft_strcat   strcat
#define ft_strcmp   strcmp
#define ft_strcpy   strcpy
#define ft_strlen   strlen
#define ft_strncmp  strncmp
#define ft_strncpy  strncpy
#define ft_strrchr  strrchr
#define ft_strstr   strstr


typedef struct  FT_Face_InternalRec_
{
	FT_Matrix  transform_matrix;
	FT_Vector  transform_delta;
	FT_Int     transform_flags;

	//FT_ServiceCacheRec  services;

	FT_Char              no_stem_darkening;
	uint32_t             random_seed;

#ifdef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
	FT_LcdFiveTapFilter      lcd_weights;      /* filter weights, if any */
	FT_Bitmap_LcdFilterFunc  lcd_filter_func;  /* filtering callback     */
#endif

	FT_Int  refcount;

} FT_Face_InternalRec;

typedef struct  FT_ServiceDescRec_
{
	const char* serv_id;     /* service name         */
	const void* serv_data;   /* service pointer/data */

} FT_ServiceDescRec;

typedef const FT_ServiceDescRec* FT_ServiceDesc;

/*------------FREE TYPE DEF -----------------------*/



typedef unsigned int  FT_UInt;

typedef int  FT_Error;
//#define FT_EXPORT_DEF( x )  extern  x

//typedef signed long FT_Int32;

typedef uint32_t u32;


int FT_New_Memory_Face(FT_Library library, const FT_Byte* file_base, FT_Long file_size, FT_Long face_index, FT_Face* aface);
int FT_Set_Char_Size(FT_Face  face, FT_F26Dot6  char_width, FT_F26Dot6 char_height, FT_UInt horz_resolution, FT_UInt  vert_resolution);
int FT_Load_Char(FT_Face face, FT_ULong  char_code, FT_Int32 load_flags);
int FT_Init_FreeType(FT_Library* alibrary);
int FT_Done_FreeType(FT_Library  library);
int FT_Done_Face(FT_Face  face);
int FT_New_Face(FT_Library   library, const char* filepathname, FT_Long  face_index, FT_Face* aface);
int FT_Load_Glyph(FT_Face   face, FT_UInt  glyph_index, u32 load_flags); 
FT_UInt FT_Get_Char_Index(FT_Face   face, FT_ULong  charcode);
int FT_Select_Charmap(FT_Face face, FT_Encoding  encoding);
int FT_Done_Glyph(FT_Glyph FT_Glyph);
int FT_Get_Glyph(FT_GlyphSlot slot, FT_Glyph* aglyph);
int FT_Get_Kerning(FT_Face face, FT_UInt  left_glyph, FT_UInt  right_glyph, FT_UInt  kern_mode, FT_Vector* akerning);
int FT_Glyph_Stroke(FT_Glyph* pglyph, FT_Stroker   stroker, FT_Bool  destroy);
int FT_Glyph_StrokeBorder(FT_Glyph* pglyph, FT_Stroker   stroker, FT_Bool inside, FT_Bool  destroy);
int FT_Glyph_To_Bitmap(FT_Glyph* the_glyph, FT_Render_Mode  render_mode, FT_Vector* origin, FT_Bool destroy);
int FT_Library_SetLcdFilter(FT_Library library, FT_LcdFilter  filter);
int FT_Library_SetLcdFilterWeights(FT_Library  library, unsigned char* weights);
int FT_Stroker_Done(FT_Stroker  stroker);
int FT_Stroker_New(FT_Library  library, FT_Stroker* astroker);
int FT_Stroker_Set(FT_Stroker stroker, FT_Fixed  radius, FT_Stroker_LineCap   line_cap, FT_Stroker_LineJoin  line_join, FT_Fixed  miter_limit);
int FT_Open_Face(FT_Library library,const FT_Open_Args* args,FT_Long face_index,FT_Face* aface);

int FT_Select_Size(FT_Face face, FT_Int strike_index);
int FT_Render_Glyph(FT_GlyphSlot slot,FT_Render_Mode render_mode);
void FT_Outline_Transform(const FT_Outline* outline,const FT_Matrix* matrix);
int FT_Set_Charmap(FT_Face face,FT_CharMap charmap);



/*------------ END FREE TYPE -----------------------*/

#ifdef __cplusplus
}
#endif

#endif
