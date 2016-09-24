#include "tag.h"
#include "wrapper.h"

using Nan::EscapableHandleScope;
using Nan::New;
using v8::Local;
using v8::Object;

Local<Object> ExportTag(TagLib::Tag *tag) {
    EscapableHandleScope scope;
    Local<Object> object = New<Object>();
    TagLibWrapper o(*object);
    o.SetString("title", tag->title());
    o.SetString("album", tag->album());
    o.SetString("artist", tag->artist());
    o.SetUint32("track", tag->track());
    o.SetUint32("year", tag->year());
    o.SetString("genre", tag->genre());
    o.SetString("comment", tag->comment());
    return scope.Escape(object);
}

void ImportTag(Object *object, TagLib::Tag *tag) {
    TagLibWrapper o(object);
    tag->setTitle(o.GetString("title"));
    tag->setAlbum(o.GetString("album"));
    tag->setArtist(o.GetString("artist"));
    tag->setTrack(o.GetUint32("track"));
    tag->setYear(o.GetUint32("year"));
    tag->setGenre(o.GetString("genre"));
    tag->setComment(o.GetString("comment"));
}