#pragma once

#include <d3d12.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <dxgi1_6.h>
#include <string>
#include <wrl.h>
#include "../Utility/d3dx12.h"

using namespace DirectX;
using namespace Microsoft::WRL;

namespace TrainingCamp
{
    struct Vertex
    {
        XMFLOAT3 vertex;
        XMFLOAT4 color;
    };

    class Direct3D12HelloTriangle
    {
    public:
        Direct3D12HelloTriangle(UINT width, UINT height,HWND hwnd);
        void OnInit();
        void OnUpdate();
        void OnRender();
        void OnDestroy();
    private:
        
        static const UINT FrameCount = 2;

        CD3DX12_VIEWPORT m_viewport;
        CD3DX12_RECT m_scissorRect;
        ComPtr<IDXGISwapChain3> m_swapChain;
        ComPtr<ID3D12Device> m_device;
        ComPtr<ID3D12Resource1> m_renderTargets[FrameCount];
        ComPtr<ID3D12CommandAllocator> m_commandAllocator;
        ComPtr<ID3D12CommandQueue>  m_commandQueue;
        ComPtr<ID3D12RootSignature> m_rootSignature;
        ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
        ComPtr<ID3D12PipelineState> m_pipelineState;
        ComPtr<ID3D12GraphicsCommandList> m_commandList;
        UINT m_rtvDescriptorSize;

        ComPtr<ID3D12Resource1> m_vertexBuffer;
        D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

        UINT m_frameIndex;
        HANDLE m_fenceEvent;
        ComPtr<ID3D12Fence> m_fence;
        UINT64 m_fenceValue;

        UINT m_width;
        UINT m_height;
        float m_aspectRatio;
        HWND m_hwnd;

        bool m_useWarpDevice;

        void LoadPipeline();
        void LoadAssets();
        void PopulateCommnadList();
        void WaitForPreviousFrame();
    };
}