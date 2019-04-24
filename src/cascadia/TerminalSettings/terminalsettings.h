/*++
Copyright (c) Microsoft Corporation

Module Name:
- TerminalSettings.h

Abstract:
- The implementation of the TerminalSettings winrt class. Provides both
        terminal control settings and terminal core settings.
Author(s):
- Mike Griese - March 2019

--*/
#pragma once

#include <conattrs.hpp>
#include "TerminalSettings.g.h"

namespace winrt::Microsoft::Terminal::Settings::implementation
{
    struct TerminalSettings : TerminalSettingsT<TerminalSettings>
    {
        TerminalSettings();

        // --------------------------- Core Settings ---------------------------
        //  All of these settings are defined in ICoreSettings.
        uint32_t DefaultForeground();
        void DefaultForeground(uint32_t value);
        uint32_t DefaultBackground();
        void DefaultBackground(uint32_t value);
        uint32_t GetColorTableEntry(int32_t index) const;
        void SetColorTableEntry(int32_t index, uint32_t value);
        int32_t HistorySize();
        void HistorySize(int32_t value);
        int32_t InitialRows();
        void InitialRows(int32_t value);
        int32_t InitialCols();
        void InitialCols(int32_t value);
        bool SnapOnInput();
        void SnapOnInput(bool value);
        // ------------------------ End of Core Settings -----------------------

        bool UseAcrylic();
        void UseAcrylic(bool value);
        double TintOpacity();
        void TintOpacity(double value);
        hstring Padding();
        void Padding(hstring value);

        hstring FontFace();
        void FontFace(hstring const& value);
        int32_t FontSize();
        void FontSize(int32_t value);

        winrt::Microsoft::Terminal::Settings::IKeyBindings KeyBindings();
        void KeyBindings(winrt::Microsoft::Terminal::Settings::IKeyBindings const& value);

        hstring Commandline();
        void Commandline(hstring const& value);

        hstring StartingDirectory();
        void StartingDirectory(hstring const& value);

        hstring EnvironmentVariables();
        void EnvironmentVariables(hstring const& value);

        ScrollbarState ScrollState() const noexcept;
        void ScrollState(winrt::Microsoft::Terminal::Settings::ScrollbarState const& value) noexcept;

    private:
        uint32_t _defaultForeground;
        uint32_t _defaultBackground;
        std::array<uint32_t, COLOR_TABLE_SIZE> _colorTable;
        int32_t _historySize;
        int32_t _initialRows;
        int32_t _initialCols;
        bool _snapOnInput;

        bool _useAcrylic;
        double _tintOpacity;
        hstring _fontFace;
        int32_t _fontSize;
        hstring _padding;
        hstring _commandline;
        hstring _startingDir;
        hstring _envVars;
        Settings::IKeyBindings _keyBindings;
        Settings::ScrollbarState _scrollbarState;
    };
}

namespace winrt::Microsoft::Terminal::Settings::factory_implementation
{
    struct TerminalSettings : TerminalSettingsT<TerminalSettings, implementation::TerminalSettings>
    {
    };
}
