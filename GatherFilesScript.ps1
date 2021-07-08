$items = "Injector32.exe", "Injector64.exe", "Viewer32.exe", "Viewer64.exe", "D3D12Hook32.dll", "D3D12Hook64.dll"

foreach ($file in $items)
{
	
	Get-ChildItem -Path "Distribute" -Filter $file -Recurse | foreach { $_.Delete()}
	$path = Get-ChildItem -Path "" -Filter $file -Recurse -ErrorAction SilentlyContinue -Force
	if ($path)
	{
		Copy-Item $path.FullName -Destination "Distribute\\"
	}
	else
	{
		Write-Host "Could not find file:" $file
	}
}