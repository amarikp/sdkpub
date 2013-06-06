Attribute VB_Name = "NIDAQ32R"
'***************************************************************************
'*
'*    NI-DAQ Windows - Function Prototypes for Visual Basic
'*    Copyright    (C) National Instruments 1995.
'*
'**************************************************************************
Declare Function AI_Change_Parameter% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c&, ByVal d&)
Declare Function AI_Check% Lib "nidaq32.dll" (ByVal a%, b%, c%)
Declare Function AI_Clear% Lib "nidaq32.dll" (ByVal a%)
Declare Function AI_Configure% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f%)
Declare Function AI_Mux_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%)
Declare Function AI_Read% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d%)
Declare Function AI_Read32% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d&)
Declare Function AI_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function AI_VRead% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d#)
Declare Function AI_VScale% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d#, ByVal e#, ByVal f%, g#)
Declare Function Align_DMA_Buffer% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c As Any, ByVal d&, ByVal e&, f&)
Declare Function AO_Calibrate% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function AO_Configure% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e#, ByVal f%)
Declare Function AO_Change_Parameter% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c&, ByVal d&)
Declare Function AO_Update% Lib "nidaq32.dll" (ByVal a%)
Declare Function AO_VWrite% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c#)
Declare Function AO_Write% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function Calibrate_E_Series% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, ByVal d#)
Declare Function Calibrate_59xx% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c#)
Declare Function Calibrate_DSA% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c#)
Declare Function Config_Alarm_Deadband% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c$, ByVal d#, ByVal e#, ByVal f%, ByVal g%, ByVal h%, ByVal i&)
Declare Function Config_ATrig_Event_Message% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c$, ByVal d#, ByVal e#, ByVal f%, ByVal g&, ByVal h&, ByVal i&, ByVal j%, ByVal k%, ByVal l&)
Declare Function Config_DAQ_Event_Message% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c$, ByVal d%, ByVal e&, ByVal f&, ByVal g&, ByVal h&, ByVal i&, ByVal j%, ByVal k%, ByVal l&)
Declare Function Configure_HW_Analog_Trigger% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, ByVal d&, ByVal e&, ByVal f&)
Declare Function CTR_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f%)
Declare Function CTR_EvCount% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%)
Declare Function CTR_EvRead% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d%)
Declare Function CTR_FOUT_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%)
Declare Function CTR_Period% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function CTR_Pulse% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%)
Declare Function CTR_Rate% Lib "nidaq32.dll" (ByVal a#, ByVal b#, c%, d%, e%)
Declare Function CTR_Reset% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function CTR_Restart% Lib "nidaq32.dll" (ByVal a%, ByVal b%)
Declare Function CTR_Simul_Op% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, ByVal d%)
Declare Function CTR_Square% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%)
Declare Function CTR_State% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%)
Declare Function CTR_Stop% Lib "nidaq32.dll" (ByVal a%, ByVal b%)
Declare Function DAQ_Check% Lib "nidaq32.dll" (ByVal a%, b%, c&)
Declare Function DAQ_Clear% Lib "nidaq32.dll" (ByVal a%)
Declare Function DAQ_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function DAQ_DB_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%)
Declare Function DAQ_DB_HalfReady% Lib "nidaq32.dll" (ByVal a%, b%, c%)
Declare Function DAQ_DB_Transfer% Lib "nidaq32.dll" (ByVal a%, b As Any, c&, d%)
Declare Function DAQ_Monitor% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d&, e As Any, f&, g%)
Declare Function DAQ_Op% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d As Any, ByVal e&, ByVal f#)
Declare Function DAQ_Rate% Lib "nidaq32.dll" (ByVal a#, ByVal b%, c%, d%)
Declare Function DAQ_Start% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d As Any, ByVal e&, ByVal f%, ByVal g%)
Declare Function DAQ_StopTrigger_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c&)
Declare Function DAQ_to_Disk% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d$, ByVal e&, ByVal f#, ByVal g%)
Declare Function DAQ_VScale% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d#, ByVal e#, ByVal f&, g%, h#)
Declare Function DIG_Block_Check% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c&)
Declare Function DIG_Block_Clear% Lib "nidaq32.dll" (ByVal a%, ByVal b%)
Declare Function DIG_Block_In% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c As Any, ByVal d&)
Declare Function DIG_Block_Out% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c As Any, ByVal d&)
Declare Function DIG_Block_PG_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f%, ByVal g%)
Declare Function DIG_DB_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%)
Declare Function DIG_DB_HalfReady% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%)
Declare Function DIG_DB_Transfer% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c As Any, ByVal d&)
Declare Function DIG_Grp_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%)
Declare Function DIG_Grp_Mode% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f%, ByVal g%)
Declare Function DIG_Grp_Status% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%)
Declare Function DIG_In_Grp% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%)
Declare Function DIG_In_Line% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d%)
Declare Function Query_Optimizations_GFS% Lib "nidaq32.dll" (ByVal a%)
Declare Function DIG_In_Port_GFS% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%)
Declare Function DIG_In_Port% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%)
Declare Function DIG_Line_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%)
Declare Function DIG_Out_Grp% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function DIG_Out_Line% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%)
Declare Function DIG_Out_Port_GFS% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function DIG_Out_Port% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function DIG_Prt_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%)
Declare Function DIG_Prt_Status% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%)
Declare Function DIG_SCAN_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d%, ByVal e%)
Declare Function Get_DAQ_Device_Info% Lib "nidaq32.dll" (ByVal a%, ByVal b&, c&)
Declare Function Get_DAQ_Event% Lib "nidaq32.dll" (ByVal a&, b%, c%, d%, e&)
Declare Function Get_NI_DAQ_Version% Lib "nidaq32.dll" (a&)
Declare Function GPCTR_Config_Buffer% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, ByVal d&, e As Any)
Declare Function GPCTR_Read_Buffer% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, ByVal d&, ByVal e&, ByVal f#, g&, h&)
Declare Function Line_Change_Attribute% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, ByVal d&)
Declare Function GPCTR_Control% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&)
Declare Function GPCTR_Set_Application% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&)
Declare Function GPCTR_Watch% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, d&)
Declare Function ICTR_Read% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%)
Declare Function ICTR_Reset% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function ICTR_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%)
Declare Function Init_DA_Brds% Lib "nidaq32.dll" (ByVal a%, b%)
Declare Function Lab_ISCAN_Check% Lib "nidaq32.dll" (ByVal a%, b%, c&, d%)
Declare Function Lab_ISCAN_Op% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d As Any, ByVal e&, ByVal f#, ByVal g#, h%)
Declare Function Lab_ISCAN_Start% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d As Any, ByVal e&, ByVal f%, ByVal g%, ByVal h%)
Declare Function Lab_ISCAN_to_Disk% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d$, ByVal e&, ByVal f#, ByVal g#, ByVal h%)
Declare Function LPM16_Calibrate% Lib "nidaq32.dll" (ByVal a%)
Declare Function MIO_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function Peek_DAQ_Event% Lib "nidaq32.dll" (ByVal a&, b%, c%, d%, e&)
Declare Function REG_Level_Read% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c&)
Declare Function REG_Level_Write% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c&, ByVal d&, e&)
Declare Function RTSI_Clear% Lib "nidaq32.dll" (ByVal a%)
Declare Function RTSI_Clock% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function RTSI_Conn% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%)
Declare Function RTSI_DisConn% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function SC_2040_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function SCAN_Demux% Lib "nidaq32.dll" (a%, ByVal b&, ByVal c%, ByVal d%)
Declare Function SCAN_Op% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d%, e As Any, ByVal f&, ByVal g#, ByVal h#)
Declare Function SCAN_Sequence_Demux% Lib "nidaq32.dll" (ByVal a%, b%, ByVal c&, d%, ByVal e%, f%, g&)
Declare Function SCAN_Sequence_Retrieve% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%)
Declare Function SCAN_Sequence_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d%, e%, f%, g%)
Declare Function SCAN_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d%)
Declare Function SCAN_Start% Lib "nidaq32.dll" (ByVal a%, b As Any, ByVal c&, ByVal d%, ByVal e%, ByVal f%, ByVal g%)
Declare Function SCAN_to_Disk% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d%, ByVal e$, ByVal f&, ByVal g#, ByVal h#, ByVal i%)
Declare Function Calibrate_1200% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f%, ByVal g%, ByVal h%, ByVal i#, ByVal j#)
Declare Function SCXI_AO_Write% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f#, ByVal g%, h%)
Declare Function SCXI_Cal_Constants% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f%, ByVal g#, ByVal h%, ByVal i%, ByVal j%, ByVal k#, ByVal l#, ByVal m#, ByVal n#, ByVal o#, p#, q#)
Declare Function InitChannelWizardStrainCal% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e!, ByVal f!, g#, h%, i%, ByVal j!, ByVal k%)
Declare Function ChannelWizardSCXIStrainCal% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f#, ByVal g%, ByVal h$, ByVal i$, j#, k#, l#)
Declare Function SCXI_1520_Transducer_Cal% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d#, ByVal e%, ByVal f%)
Declare Function SCXI_Calibrate% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f#, ByVal g#, ByVal h%, ByVal i%)
Declare Function SCXI_Strain_Null% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, f!)
Declare Function SCXI_Strain_Null_Ex% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, f!, ByVal g!, ByVal h&, i%, j%)
Declare Function SCXI_Calibrate_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function SCXI_Change_Chan% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function SCXI_Set_Potentiometer% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e$)
Declare Function SCXI_Set_Excitation% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e!, f!)
Declare Function SCXI_Configure_Connection% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%)
Declare Function SCXI_Configure_Filter% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e#, ByVal f%, ByVal g%, h#)
Declare Function SCXI_Get_Chassis_Info% Lib "nidaq32.dll" (ByVal a%, b%, c%, d%, e%, f%)
Declare Function SCXI_Get_Module_Info% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c&, d%, e%)
Declare Function SCXI_Get_State% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, e&)
Declare Function SCXI_Get_Status% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, d&)
Declare Function SCXI_Load_Config% Lib "nidaq32.dll" (ByVal a%)
Declare Function SCXI_MuxCtr_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%)
Declare Function SCXI_Reset% Lib "nidaq32.dll" (ByVal a%, ByVal b%)
Declare Function SCXI_Scale% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d#, ByVal e#, ByVal f%, ByVal g%, ByVal h%, ByVal i&, j%, k#)
Declare Function SCXI_SCAN_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d%, e%, ByVal f%, ByVal g%)
Declare Function SCXI_Set_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f%, g&, h%, i%)
Declare Function SCXI_Set_Gain% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d#)
Declare Function SCXI_Set_Input_Mode% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function SCXI_Set_State% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e&)
Declare Function SCXI_Single_Chan_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%)
Declare Function SCXI_Track_Hold_Control% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%)
Declare Function SCXI_Track_Hold_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f%, ByVal g%)
Declare Function Select_Signal% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, ByVal d&)
Declare Function Set_DAQ_Device_Info% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&)
Declare Function Timeout_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b&)
Declare Function WFM_Chan_Control% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function WFM_Check% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d&, e&)
Declare Function WFM_ClockRate% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e&, ByVal f%)
Declare Function WFM_DB_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, ByVal d%, ByVal e%, ByVal f%)
Declare Function WFM_DB_HalfReady% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d%)
Declare Function WFM_DB_Transfer% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d As Any, ByVal e&)
Declare Function WFM_from_Disk% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, ByVal d$, ByVal e&, ByVal f&, ByVal g&, ByVal h#)
Declare Function WFM_Group_Control% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%)
Declare Function WFM_Group_Setup% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, ByVal d%)
Declare Function WFM_Load% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d As Any, ByVal e&, ByVal f&, ByVal g%)
Declare Function WFM_Op% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c%, d As Any, ByVal e&, ByVal f&, ByVal g#)
Declare Function WFM_Rate% Lib "nidaq32.dll" (ByVal a#, ByVal b%, c%, d&)
Declare Function WFM_Scale% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c&, ByVal d#, e#, f%)
Declare Function AI_Read_Scan% Lib "nidaq32.dll" (ByVal a%, b%)
Declare Function AI_VRead_Scan% Lib "nidaq32.dll" (ByVal a%, b#)
Declare Function SCXI_ModuleID_Read% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c&)
Declare Function AO_VScale% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c#, d%)
Declare Function GPCTR_Change_Parameter% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, ByVal d&)
Declare Function USE_MIO% Lib "nidaq32.dll" ()
Declare Function USE_LPM% Lib "nidaq32.dll" ()
Declare Function USE_LAB% Lib "nidaq32.dll" ()
Declare Function USE_DIO_96% Lib "nidaq32.dll" ()
Declare Function USE_DIO_32F% Lib "nidaq32.dll" ()
Declare Function USE_DIO_24% Lib "nidaq32.dll" ()
Declare Function USE_AO_610% Lib "nidaq32.dll" ()
Declare Function USE_AO_2DC% Lib "nidaq32.dll" ()
Declare Function DIG_Trigger_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d%, ByVal e%, ByVal f%, ByVal g&, ByVal h&, ByVal i&)
Declare Function SCXI_Set_Threshold% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c%, ByVal d#, ByVal e#)
Declare Function WFM_Set_Clock% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c&, ByVal d#, ByVal e&, f#)
Declare Function DAQ_Set_Clock% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c#, ByVal d&, e#)
Declare Function Tio_Select_Signal% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, ByVal d&)
Declare Function Tio_Combine_Signals% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&)
Declare Function DIG_In_Prt% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c&)
Declare Function DIG_Out_Prt% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c&)
Declare Function AI_Get_Overloaded_Channels% Lib "nidaq32.dll" (ByVal a%, b%, c%)
Declare Function Calibrate_TIO% Lib "nidaq32.dll" (ByVal a%, ByVal b&, ByVal c&, ByVal d#)
Declare Function DIG_Change_Message_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c$, ByVal d$, ByVal e%, ByVal f%, ByVal g&)
Declare Function DIG_Change_Message_Control% Lib "nidaq32.dll" (ByVal a%, ByVal b%)
Declare Function DIG_Filter_Config% Lib "nidaq32.dll" (ByVal a%, ByVal b%, ByVal c$, ByVal d#)
Declare Function SCXI_TerminalBlockID_Read% Lib "nidaq32.dll" (ByVal a%, ByVal b%, c&)
Declare Function ni62xx_CalStart% Lib "nidaq32.dll" (ByVal a%, ByVal b$)
Declare Function ni62xx_CalAdjust% Lib "nidaq32.dll" (ByVal a%, ByVal b&, c#, ByVal d%)
Declare Function ni62xx_CalEnd% Lib "nidaq32.dll" (ByVal a%, ByVal b&)
Declare Function ni62xx_SelfCalibrate% Lib "nidaq32.dll" (ByVal a%)
Declare Function CalFetchInternalReference% Lib "nidaq32.dll" (ByVal a%, b#)
Declare Function CalChangePassword% Lib "nidaq32.dll" (ByVal a%, ByVal b$, ByVal c$)
Declare Function CalFetchCount% Lib "nidaq32.dll" (ByVal a%, ByVal b&, c&)
Declare Function CalFetchDate% Lib "nidaq32.dll" (ByVal a%, ByVal b&, c&, d&, e&)
Declare Function CalFetchTemperature% Lib "nidaq32.dll" (ByVal a%, ByVal b&, c#)
Declare Function CalFetchMiscInfo% Lib "nidaq32.dll" (ByVal a%, ByVal b$)
Declare Function CalStoreMiscInfo% Lib "nidaq32.dll" (ByVal a%, ByVal b$)



