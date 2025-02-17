////////////////////////////////////////////////////////////////////////////////
///   __    __         __ 
///  |  | _|__|_  _  _|__|   Kit for Interactive World Integration
///  |  |/ /  \ \/ \/ /  |   A 2D game map editor
///  |    <|  |\  _  /|  |   ( version 0.0.3 dev )
///  |__|_ \__| \/ \/ |__|   https://github.com/metayeti/kiwi
///       \/              
///
///  Licensed under GPL3 ( https://www.gnu.org/licenses/gpl-3.0.en.html )
///  Based on the wxWidgets library ( https://www.wxwidgets.org/ )
///
///  Copyright (c) 2024 Danijel Durakovic
///
/// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
///
///  dlg_game.h
///
////////////////////////////////////////////////////////////////////////////////

#include "../kiwi.h"
#include "dlg_game.h"

#include <string>
#include <vector>


void kiwi::DlgGame::OnPaint(wxPaintEvent& e)
{
    wxBufferedPaintDC dc(this);

    wxSize paint_zone(300,200);

    dc.SetBrush(*wxBLACK_BRUSH);
    dc.SetPen(wxPen(*wxBLUE, 4, wxPENSTYLE_SOLID));
    dc.DrawRectangle(wxPoint(0, 0), wxSize(300,200));
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.SetPen(wxPen(*wxBLACK, 4, wxPENSTYLE_SOLID));
    dc.DrawRectangle(wxPoint(100, 100), wxSize(paint_zone.GetWidth() - 250, paint_zone.GetHeight() - 250));
}

kiwi::DlgGame::DlgGame(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "game", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(DlgGame::OnPaint));
}