using HoloToolkit;
using UnityEngine;

/// <summary>
/// CursorManager class takes Cursor GameObjects.
/// One that is on Holograms and another off Holograms.
/// Shows the appropriate Cursor when a Hologram is hit.
/// Places the appropriate Cursor at the hit position.
/// Matches the Cursor normal to the hit surface.
/// </summary>
public class CursorManager : Singleton<CursorManager>
{
    [Tooltip("Drag the Cursor object to show when it hits a hologram.")]
    public GameObject CursorOnHolograms;

    [Tooltip("Drag the Cursor object to show when it does not hit a hologram.")]
    public GameObject CursorOffHolograms;

    void Awake()
    {
        if (CursorOnHolograms == null || CursorOffHolograms == null)
        {
            return;
        }

        // Hide the Cursors to begin with.
        CursorOnHolograms.SetActive(false);
        CursorOffHolograms.SetActive(false);
    }

    void Update()
    {
        if (GazeManager.Instance == null || CursorOnHolograms == null || CursorOffHolograms == null)
        {
            return;
        }

        if(GazeManager.Instance.Position.y > 0)
        {
            CursorOffHolograms.SetActive(false);
            CursorOnHolograms.SetActive(true);
        }
        else
        {
            CursorOffHolograms.SetActive(true);
            CursorOnHolograms.SetActive(false);
        }
        // 2.b: Assign gameObject's transform position equals GazeManager's instance Position.
        gameObject.transform.position = GazeManager.Instance.Position;
        // 2.b: Assign gameObject's transform up vector equals GazeManager's instance Normal.
        gameObject.transform.up = GazeManager.Instance.Normal;
    }
}