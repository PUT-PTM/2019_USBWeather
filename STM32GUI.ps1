#region Script Settings
#<ScriptSettings xmlns="http://tempuri.org/ScriptSettings.xsd">
#  <ScriptPackager>
#    <process>powershell.exe</process>
#    <arguments />
#    <extractdir>%TEMP%</extractdir>
#    <files />
#    <usedefaulticon>true</usedefaulticon>
#    <showinsystray>false</showinsystray>
#    <altcreds>false</altcreds>
#    <efs>true</efs>
#    <ntfs>true</ntfs>
#    <local>false</local>
#    <abortonfail>true</abortonfail>
#    <product />
#    <version>1.0.0.1</version>
#    <versionstring />
#    <comments />
#    <company />
#    <includeinterpreter>false</includeinterpreter>
#    <forcecomregistration>false</forcecomregistration>
#    <consolemode>false</consolemode>
#    <EnableChangelog>false</EnableChangelog>
#    <AutoBackup>false</AutoBackup>
#    <snapinforce>false</snapinforce>
#    <snapinshowprogress>false</snapinshowprogress>
#    <snapinautoadd>2</snapinautoadd>
#    <snapinpermanentpath />
#    <cpumode>1</cpumode>
#    <hidepsconsole>false</hidepsconsole>
#  </ScriptPackager>
#</ScriptSettings>
#endregion

#region ScriptForm Designer

#region Constructor

[void][System.Reflection.Assembly]::LoadWithPartialName("System.Windows.Forms")
[void][System.Reflection.Assembly]::LoadWithPartialName("System.Drawing")

#endregion

#region Post-Constructor Custom Code

#endregion

#region Form Creation
#Warning: It is recommended that changes inside this region be handled using the ScriptForm Designer.
#When working with the ScriptForm designer this region and any changes within may be overwritten.
#~~< Form1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Form1 = New-Object System.Windows.Forms.Form
$Form1.ClientSize = New-Object System.Drawing.Size(326, 160)
$Form1.Text = "STM32GUI"
#~~< tbx1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$tbx1 = New-Object System.Windows.Forms.TextBox
$tbx1.Location = New-Object System.Drawing.Point(12, 78)
$tbx1.Size = New-Object System.Drawing.Size(195, 20)
$tbx1.TabIndex = 1
$tbx1.Text = ""
$tbx1.add_TextChanged({TextBox1TextChanged($tbx1)})
#~~< btnSend >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$btnSend = New-Object System.Windows.Forms.Button
$btnSend.Location = New-Object System.Drawing.Point(229, 75)
$btnSend.Size = New-Object System.Drawing.Size(75, 23)
$btnSend.TabIndex = 0
$btnSend.Text = "wyslij"
$btnSend.UseVisualStyleBackColor = $true
$btnSend.add_Click({btnSendClick($btnSend)})
$Form1.Controls.Add($tbx1)
$Form1.Controls.Add($btnSend)

#endregion

#region Custom Code
$port = [System.IO.Ports.SerialPort]::new("COM3",9600,"None",8,[System.IO.Ports.StopBits]::One)
$port.Open();

#endregion

#region Event Loop

function Main{
	[System.Windows.Forms.Application]::EnableVisualStyles()
	[System.Windows.Forms.Application]::Run($Form1)
}

#endregion

#endregion

#region Event Handlers

function TextBox1TextChanged( $object ){

}

function btnSendClick( $object ){
		$port.Write($tbx1.Text);	
	
		
	
}

Main #This call must remain below all other event functions

#endregion
